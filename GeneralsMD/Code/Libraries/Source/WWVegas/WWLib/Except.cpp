/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/wwlib/Except.cpp                             $*
 *                                                                                             *
 *                      $Author:: Steve_t                                                     $*
 *                                                                                             *
 *                     $Modtime:: 2/07/02 12:28p                                              $*
 *                                                                                             *
 *                    $Revision:: 14                                                          $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *                                                                                             *
 * Exception_Proc -- Windows dialog callback for the exception dialog                          *
 * Exception_Dialog -- Brings up the exception options dialog.                                 *
 * Add_Txt -- Add the given text to the machine state dump buffer.                             *
 * Dump_Exception_Info -- Dump machine state information into a buffer                         *
 * Exception_Handler -- Exception handler filter function                                      *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifdef _MSC_VER

#include	"always.h"
#include <windows.h>
#include	"assert.h"
#include "cpudetect.h"
#include	"except.h"
//#include "debug.h"
#include "mpu.h"
//#include "commando\nat.h"
#include "thread.h"
#include "wwdebug.h"
#include "wwmemlog.h"

#include	<conio.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
#include <crtdbg.h>
#include	<stdio.h>

#ifdef WWDEBUG
#define DebugString 	WWDebug_Printf
#else
void DebugString(char const *, ...){};
#endif //WWDEBUG

/*
** Enable this define to get the 'demo timed out' message on a crash or assert failure.
*/
//#define DEMO_TIME_OUT

/*
** Buffer to dump machine state information to. We don't want to allocate this at run-time
** in case the exception was caused by a malfunction in the memory system.
*/
static char ExceptionText [65536];

bool SymbolsAvailable = false;
HINSTANCE ImageHelp = (HINSTANCE) -1;

void (*AppCallback)(void) = NULL;
char *(*AppVersionCallback)(void) = NULL;

/*
** Flag to indicate we should exit when an exception occurs.
*/
bool ExitOnException = false;
bool TryingToExit = false;

/*
** Register dump variables. These are used to allow the game to restart from an arbitrary
** position after an exception occurs.
*/
unsigned long ExceptionReturnStack = 0;
unsigned long ExceptionReturnAddress = 0;
unsigned long ExceptionReturnFrame = 0;

/*
** Number of times the exception handler has recursed. Recursions are bad.
*/
int ExceptionRecursions = -1;

/*
** List of threads that the exception handler knows about.
*/
DynamicVectorClass<ThreadInfoType*> ThreadList;

// Direct dbghelp linking
#pragma comment(lib, "dbghelp.lib")



/***********************************************************************************************
 * _purecall -- This function overrides the C library Pure Virtual Function Call error         *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   0 = no error                                                                      *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   8/22/00 11:42AM ST : Created                                                              *
 *=============================================================================================*/
int __cdecl _purecall(void)
{
	int return_code = 0;

#ifdef WWDEBUG
	/*
	** Use int3 to cause an exception.
	*/
	WWDEBUG_SAY(("Pure Virtual Function call. Oh No!\n"));
	__debugbreak();
#endif	//_DEBUG_ASSERT

	return(return_code);
}



/***********************************************************************************************
 * Last_Error_Text -- Get the system error text for GetLastError                                *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Ptr to error string                                                               *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   8/14/98 11:11AM ST : Created                                                              *
 *=============================================================================================*/
char const * Last_Error_Text(void)
{
	static char message_buffer[256];
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), &message_buffer[0], 256, NULL);
	return (message_buffer);
}



/***********************************************************************************************
 * Add_Txt -- Add the given text to the machine state dump buffer.                             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Text                                                                              *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    7/22/97 12:21PM ST : Created                                                             *
 *=============================================================================================*/
static void Add_Txt (char const *txt)
{
	if (strlen(ExceptionText) + strlen(txt) < 65535) {
		strcat(ExceptionText, txt);
	}
#if (0)
	/*
	** Log to debug output too.
	*/
	static char _debug_output_txt[512];
	const char *in = txt;
	char *out = _debug_output_txt;
	bool done = false;

	if (strlen(txt) < sizeof(_debug_output_txt)) {
		for (int i=0 ; i<sizeof(_debug_output_txt) ; i++) {

			switch (*in) {
				case '\r':
					in++;
					continue;

				case 0:
					done = true;
					// fall through

				default:
					*out++ = *in++;
					break;
			}

			if (done) {
				break;
			}
		}

		DebugString(_debug_output_txt);
	}
#endif //(0)
}



/***********************************************************************************************
 * Dump_Exception_Info -- Dump machine state information into a buffer                         *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    ptr to exception information                                                      *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    7/22/97 12:21PM ST : Created                                                             *
 *=============================================================================================*/
void Dump_Exception_Info(EXCEPTION_POINTERS *e_info)
{
	static const unsigned int _codes[] = {
		EXCEPTION_ACCESS_VIOLATION, EXCEPTION_ARRAY_BOUNDS_EXCEEDED,
		EXCEPTION_BREAKPOINT, EXCEPTION_DATATYPE_MISALIGNMENT,
		EXCEPTION_FLT_DENORMAL_OPERAND, EXCEPTION_FLT_DIVIDE_BY_ZERO,
		EXCEPTION_FLT_INEXACT_RESULT, EXCEPTION_FLT_INVALID_OPERATION,
		EXCEPTION_FLT_OVERFLOW, EXCEPTION_FLT_STACK_CHECK,
		EXCEPTION_FLT_UNDERFLOW, EXCEPTION_ILLEGAL_INSTRUCTION,
		EXCEPTION_IN_PAGE_ERROR, EXCEPTION_INT_DIVIDE_BY_ZERO,
		EXCEPTION_INT_OVERFLOW, EXCEPTION_INVALID_DISPOSITION,
		EXCEPTION_NONCONTINUABLE_EXCEPTION, EXCEPTION_PRIV_INSTRUCTION,
		EXCEPTION_SINGLE_STEP, EXCEPTION_STACK_OVERFLOW, 0xffffffff
	};

	static char const *_code_txt[] = {
		"Error code: EXCEPTION_ACCESS_VIOLATION\r\r\nDescription: The thread tried to read from or write to a virtual address for which it does not have the appropriate access.",
		"Error code: EXCEPTION_ARRAY_BOUNDS_EXCEEDED\r\r\nDescription: The thread tried to access an array element that is out of bounds...",
		"Error code: EXCEPTION_BREAKPOINT\r\r\nDescription: A breakpoint was encountered.",
		"Error code: EXCEPTION_DATATYPE_MISALIGNMENT\r\r\nDescription: The thread tried to read or write data that is misaligned...",
		"Error code: EXCEPTION_FLT_DENORMAL_OPERAND\r\r\nDescription: One of the operands in a floating-point operation is denormal...",
		"Error code: EXCEPTION_FLT_DIVIDE_BY_ZERO\r\r\nDescription: The thread tried to divide a floating-point value by a floating-point divisor of zero.",
		"Error code: EXCEPTION_FLT_INEXACT_RESULT\r\r\nDescription: The result of a floating-point operation cannot be represented exactly...",
		"Error code: EXCEPTION_FLT_INVALID_OPERATION\r\r\nDescription: Some strange unknown floating point operation was attempted.",
		"Error code: EXCEPTION_FLT_OVERFLOW\r\r\nDescription: The exponent of a floating-point operation is greater than the magnitude allowed...",
		"Error code: EXCEPTION_FLT_STACK_CHECK\r\r\nDescription: The stack overflowed or underflowed as the result of a floating-point operation.",
		"Error code: EXCEPTION_FLT_UNDERFLOW\r\r\nDescription: The exponent of a floating-point operation is less than the magnitude allowed...",
		"Error code: EXCEPTION_ILLEGAL_INSTRUCTION\r\r\nDescription: The thread tried to execute an invalid instruction.",
		"Error code: EXCEPTION_IN_PAGE_ERROR\r\r\nDescription: The thread tried to access a page that was not present...",
		"Error code: EXCEPTION_INT_DIVIDE_BY_ZERO\r\r\nDescription: The thread tried to divide an integer value by an integer divisor of zero.",
		"Error code: EXCEPTION_INT_OVERFLOW\r\r\nDescription: The result of an integer operation caused a carry out...",
		"Error code: EXCEPTION_INVALID_DISPOSITION\r\r\nDescription: An exception handler returned an invalid disposition...",
		"Error code: EXCEPTION_NONCONTINUABLE_EXCEPTION\r\r\nDescription: The thread tried to continue execution after a noncontinuable exception occurred.",
		"Error code: EXCEPTION_PRIV_INSTRUCTION\r\r\nDescription: The thread tried to execute an instruction whose operation is not allowed...",
		"Error code: EXCEPTION_SINGLE_STEP\r\r\nDescription: A trace trap or other single-instruction mechanism signaled that one instruction has been executed.",
		"Error code: EXCEPTION_STACK_OVERFLOW\r\r\nDescription: The thread used up its stack.",
		"Error code: ?????\r\r\nDescription: Unknown exception."
	};

	DebugString("Dump exception info\n");
	char scrap[256];
	memset(ExceptionText, 0, sizeof(ExceptionText));

	CONTEXT *context = e_info->ContextRecord;

	int access_read_write = -1;
	DWORD64 access_address = 0;
	if (e_info->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
		access_read_write = (int)e_info->ExceptionRecord->ExceptionInformation[0];
		access_address = e_info->ExceptionRecord->ExceptionInformation[1];
	}

	int i = 0;
	for (; _codes[i] != 0xffffffff; i++) {
		if (_codes[i] == e_info->ExceptionRecord->ExceptionCode) break;
	}
	Add_Txt(_code_txt[i]);
	Add_Txt("\r\n");

	if (e_info->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
		sprintf_s(scrap, "Access address: %016llX ", access_address);
		Add_Txt(scrap);
		Add_Txt(access_read_write ? "was written to.\r\n" : "was read from.\r\n");
	}

	char symbol[sizeof(IMAGEHLP_SYMBOL64) + 256] = {};
	IMAGEHLP_SYMBOL64 *symptr = (IMAGEHLP_SYMBOL64 *)symbol;
	symptr->SizeOfStruct = sizeof(IMAGEHLP_SYMBOL64);
	symptr->MaxNameLength = 256;
	symptr->Address = context->Rip;

	DWORD64 disp64 = 0;
	if (SymGetSymFromAddr64(GetCurrentProcess(), context->Rip, &disp64, symptr)) {
		sprintf_s(scrap, "Exception occurred at %016llX - %s + %llX\r\n", context->Rip, symptr->Name, disp64);
	} else {
		sprintf_s(scrap, "Exception occurred at %016llX\r\n", context->Rip);
	}
	Add_Txt(scrap);

	Add_Txt("\r\n  Stack walk...\r\n");
	DWORD64 ret_addrs[128];
	int num_addr = Stack_Walk(ret_addrs, 128, context);
	for (int s = 0; s < num_addr; s++) {
		for (int sp = 0; sp <= s; sp++) Add_Txt("  ");
		disp64 = 0;
		symptr->SizeOfStruct = sizeof(IMAGEHLP_SYMBOL64) + 256;
		symptr->MaxNameLength = 256;
		symptr->Address = ret_addrs[s];
		if (SymGetSymFromAddr64(GetCurrentProcess(), ret_addrs[s], &disp64, symptr)) {
			sprintf_s(scrap, "%s + %llX\r\n", symptr->Name, disp64);
		} else {
			sprintf_s(scrap, "%016llX\r\n", ret_addrs[s]);
		}
		Add_Txt(scrap);
	}

	if (AppVersionCallback) {
		sprintf_s(scrap, "%s\r\n\r\n", AppVersionCallback());
		Add_Txt(scrap);
	}

	Add_Txt("Thread list\r\n");
	for (int t = 0; t < ThreadList.Count(); t++) {
		sprintf_s(scrap, "  ID: %08X - %s", ThreadList[t]->ThreadID, ThreadList[t]->ThreadName);
		Add_Txt(scrap);
		if (GetCurrentThreadId() == ThreadList[t]->ThreadID) Add_Txt("   ***CURRENT THREAD***");
		Add_Txt("\r\n");
	}

	sprintf_s(scrap, "\r\nCPU %s, %d Mhz, Vendor: %s\r\n",
		(char*)CPUDetectClass::Get_Processor_String(), Get_RDTSC_CPU_Speed(),
		(char*)CPUDetectClass::Get_Processor_Manufacturer_Name());
	Add_Txt(scrap);

	Add_Txt("\r\nDetails:\r\n");
	DebugString("Register dump...\n");

	sprintf_s(scrap, "Rip:%016llX\tRsp:%016llX\tRbp:%016llX\r\n", context->Rip, context->Rsp, context->Rbp);
	Add_Txt(scrap);
	sprintf_s(scrap, "Rax:%016llX\tRbx:%016llX\tRcx:%016llX\r\n", context->Rax, context->Rbx, context->Rcx);
	Add_Txt(scrap);
	sprintf_s(scrap, "Rdx:%016llX\tRsi:%016llX\tRdi:%016llX\r\n", context->Rdx, context->Rsi, context->Rdi);
	Add_Txt(scrap);
	sprintf_s(scrap, "R8:%016llX\tR9:%016llX\tR10:%016llX\r\n", context->R8, context->R9, context->R10);
	Add_Txt(scrap);
	sprintf_s(scrap, "R11:%016llX\tR12:%016llX\tR13:%016llX\r\n", context->R11, context->R12, context->R13);
	Add_Txt(scrap);
	sprintf_s(scrap, "R14:%016llX\tR15:%016llX\r\n", context->R14, context->R15);
	Add_Txt(scrap);
	sprintf_s(scrap, "EFlags:%08X\r\n", context->EFlags);
	Add_Txt(scrap);
	sprintf_s(scrap, "CS:%04X  SS:%04X  DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n",
		context->SegCs, context->SegSs, context->SegDs, context->SegEs, context->SegFs, context->SegGs);
	Add_Txt(scrap);

	DebugString("RIP bytes dump...\n");
	sprintf_s(scrap, "\r\nBytes at RIP (%016llX)  : ", context->Rip);
	Add_Txt(scrap);
	unsigned char *rip_ptr = (unsigned char *)(ULONG_PTR)context->Rip;
	char bytestr[32];
	for (int c = 0; c < 32; c++) {
		if (IsBadReadPtr(rip_ptr, 1)) {
			strcat_s(scrap, "?? ");
		} else {
			sprintf_s(bytestr, "%02X ", *rip_ptr);
			strcat_s(scrap, bytestr);
		}
		rip_ptr++;
	}
	strcat_s(scrap, "\r\n\r\n");
	Add_Txt(scrap);

	DebugString("Stack dump...\n");
	Add_Txt("Stack dump (* indicates possible code address) :\r\n");
	DWORD64 *stackptr = (DWORD64 *)context->Rsp;
	for (int j = 0; j < 1024; j++) {
		if (IsBadReadPtr(stackptr, sizeof(DWORD64))) {
			sprintf_s(scrap, "%016llX: ????????????????\r\n", (DWORD64)(ULONG_PTR)stackptr);
		} else {
			sprintf_s(scrap, "%016llX: %016llX", (DWORD64)(ULONG_PTR)stackptr, *stackptr);
			if (!IsBadCodePtr((FARPROC)*stackptr)) {
				disp64 = 0;
				symptr->SizeOfStruct = sizeof(IMAGEHLP_SYMBOL64) + 256;
				symptr->MaxNameLength = 256;
				symptr->Address = *stackptr;
				if (SymGetSymFromAddr64(GetCurrentProcess(), *stackptr, &disp64, symptr)) {
					char tmp[256];
					sprintf_s(tmp, " - %s + %llX", symptr->Name, disp64);
					strcat_s(scrap, tmp);
				} else {
					strcat_s(scrap, " *");
				}
			} else {
				strcat_s(scrap, " DATA_PTR");
			}
			strcat_s(scrap, "\r\n");
		}
		Add_Txt(scrap);
		stackptr++;
	}

	Add_Txt("\r\n\r\n");
}





/***********************************************************************************************
 * Exception_Handler -- Exception handler filter function                                      *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    exception code                                                                    *
 *           pointer to exception information pointers                                         *
 *                                                                                             *
 * OUTPUT:   EXCEPTION_EXECUTE_HANDLER -- Excecute the body of the __except construct          *
 *        or EXCEPTION_CONTINUE_SEARCH -- Pass this exception down to the debugger             *
 *        or EXCEPTION_CONTINUE_EXECUTION -- Continue to execute at the fault address          *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    7/22/97 12:29PM ST : Created                                                              *
 *=============================================================================================*/
int Exception_Handler(int exception_code, EXCEPTION_POINTERS *e_info)
{
	DebugString("Exception!\n");

#ifdef DEMO_TIME_OUT
	if ( !WindowedMode ) {
		Load_Title_Page("TITLE.PCX", true);
		MouseCursor->Release_Mouse();
		MessageBox(MainWindow, "This demo has timed out. Thank you for playing Red Alert 2.","Byeee!", MB_ICONEXCLAMATION|MB_OK);
		return (EXCEPTION_EXECUTE_HANDLER);
	}
#endif	//DEMO_TIME_OUT

	/*
	** If we were trying to quit and we got another exception then just shut down the whole shooting match right here.
	*/
	if (TryingToExit) {
		ExitProcess(0);
	}

	/*
	** Track recursions because we need to know if something here is failing.
	*/
	ExceptionRecursions++;

	if (ExceptionRecursions > 1) {
		return (EXCEPTION_CONTINUE_SEARCH);
	}

	/*
	** If there was a breakpoint then chances are it was set by a debugger. In _DEBUG mode
	** we probably should ignore breakpoints. Breakpoints become more significant in release
	** mode since there probably isn't a debugger present.
	*/
#ifdef _DEBUG
	if (exception_code == EXCEPTION_BREAKPOINT) {
		return (EXCEPTION_CONTINUE_SEARCH);
	}
#else
	exception_code = exception_code;
#endif	//_DEBUG

#ifdef WWDEBUG
	//CONTEXT *context;
#endif WWDEBUG

	if (ExceptionRecursions == 0) {

		/*
		** Create a dump of the exception info.
		*/
		Dump_Exception_Info(e_info);

		/*
		** Log the machine state to disk
		*/
		HANDLE debug_file;
		DWORD	actual;
		debug_file = CreateFile("_except.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (debug_file != INVALID_HANDLE_VALUE){
			WriteFile(debug_file, ExceptionText, strlen(ExceptionText), &actual, NULL);
			CloseHandle (debug_file);

#if (0)
#ifdef _DEBUG_PRINT
#ifndef _DEBUG
			/*
			** Copy the exception debug file to the network. No point in doing this for the debug version
			** since symbols are not normally available.
			*/
			DebugString ("About to copy debug file\n");
			char filename[512];
			if (Get_Global_Output_File_Name ("EXCEPT", filename, 512)) {
				DebugString ("Copying DEBUG.TXT to %s\n", filename);
				int result = CopyFile("debug.txt", filename, false);
				if (result == 0) {
					DebugString ("CopyFile failed with error code %d - %s\n", GetLastError(), Last_Error_Text());
				}
			}
			DebugString ("Debug file copied\n");
#endif	//_DEBUG
#endif	//_DEBUG_PRINT
#endif	//(0)

		}
	}

	/*
	** Call the apps callback function.
	*/
	if (AppCallback) {
		AppCallback();
	}

	/*
	** If an exit is required then turn of memory leak reporting (there will be lots of them) and use
	** EXCEPTION_EXECUTE_HANDLER to let us fall out of winmain.
	*/
	if (ExitOnException) {
#ifdef _DEBUG
		_CrtSetDbgFlag(0);
#endif //_DEBUG
		TryingToExit = true;

		unsigned long id = Get_Main_Thread_ID();
		if (id != GetCurrentThreadId()) {
			DebugString("Exiting due to exception in sub thread\n");
			ExitProcess(EXIT_SUCCESS);
		}

		return(EXCEPTION_EXECUTE_HANDLER);

	}
	return (EXCEPTION_CONTINUE_SEARCH);
}




/***********************************************************************************************
 * Register_Thread_ID -- Let the exception handler know about a thread                         *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Thread ID                                                                         *
 *           Thread name                                                                       *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   8/30/2001 3:04PM ST : Created                                                             *
 *=============================================================================================*/
void Register_Thread_ID(unsigned long thread_id, char *thread_name, bool main_thread)
{
	WWMEMLOG(MEM_GAMEDATA);
	if (thread_name) {

		/*
		** See if we already know about this thread. Maybe just the thread_id changed.
		*/
		for (int i=0 ; i<ThreadList.Count() ; i++) {
			if (strcmp(thread_name, ThreadList[i]->ThreadName) == 0) {
				ThreadList[i]->ThreadID = thread_id;
				return;
			}
		}

		ThreadInfoType *thread = new ThreadInfoType;
		thread->ThreadID = thread_id;
		strcpy(thread->ThreadName, thread_name);
		thread->Main = main_thread;
		thread->ThreadHandle = INVALID_HANDLE_VALUE;
		ThreadList.Add(thread);
	}
}


#if (0)
/***********************************************************************************************
 * Register_Thread_Handle -- Keep a copy of the thread handle that matches this thread ID      *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Thread ID                                                                         *
 *           Thread handle                                                                     *
 *                                                                                             *
 * OUTPUT:   True if thread ID was matched                                                     *
 *                                                                                             *
 * WARNINGS:                                                                                   *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   2/6/2002 9:40PM ST : Created                                                              *
 *=============================================================================================*/
bool Register_Thread_Handle(unsigned long thread_id, HANDLE thread_handle)
{
	for (int i=0 ; i<ThreadList.Count() ; i++) {
		if (ThreadList[i]->ThreadID == thread_id) {
			ThreadList[i]->ThreadHandle = thread_handle;
			return(true);
			break;
		}
	}
	return(false);
}



/***********************************************************************************************
 * Get_Num_Threads -- Get the number of threads being tracked.                                 *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Number of threads we know about                                                   *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   2/6/2002 9:43PM ST : Created                                                              *
 *=============================================================================================*/
int Get_Num_Threads(void)
{
	return(ThreadList.Count());
}


/***********************************************************************************************
 * Get_Thread_Handle -- Get the handle for the given thread index                              *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Thread index                                                                      *
 *                                                                                             *
 * OUTPUT:   Thread handle                                                                     *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   2/6/2002 9:46PM ST : Created                                                              *
 *=============================================================================================*/
HANDLE Get_Thread_Handle(int thread_index)
{
	if (thread_index < ThreadList.Count()) {
		return(ThreadList[thread_index]->ThreadHandle);
	}
}
#endif //(0)

/***********************************************************************************************
 * Unregister_Thread_ID -- Remove a thread entry from the thread list                          *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Thread ID                                                                         *
 *           Thread name                                                                       *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   8/30/2001 3:10PM ST : Created                                                             *
 *=============================================================================================*/
void Unregister_Thread_ID(unsigned long thread_id, char *thread_name)
{
	for (int i=0 ; i<ThreadList.Count() ; i++) {
		if (strcmp(thread_name, ThreadList[i]->ThreadName) == 0) {
			assert(ThreadList[i]->ThreadID == thread_id);
			delete ThreadList[i];
			ThreadList.Delete(i);
			return;
		}
	}
}



/***********************************************************************************************
 * Get_Main_Thread_ID -- Get the ID of the processes main thread                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Thread ID                                                                         *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/6/2001 12:20PM ST : Created                                                            *
 *=============================================================================================*/
unsigned long Get_Main_Thread_ID(void)
{
	for (int i=0 ; i<ThreadList.Count() ; i++) {
		if (ThreadList[i]->Main) {
			return(ThreadList[i]->ThreadID);
		}
	}
	return(0);
}






/***********************************************************************************************
 * Load_Image_Helper -- Load imagehlp.dll and retrieve the programs symbols                    *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   6/12/2001 4:27PM ST : Created                                                             *
 *=============================================================================================*/
void Load_Image_Helper(void)
{
	if (ImageHelp == (HINSTANCE)-1) {
		ImageHelp = LoadLibrary("IMAGEHLP.DLL");
		if (ImageHelp != NULL) {
			SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_UNDNAME);
			if (SymInitialize(GetCurrentProcess(), NULL, FALSE)) {
				char exe_name[_MAX_PATH];
				GetModuleFileName(NULL, exe_name, sizeof(exe_name));
				SymLoadModule64(GetCurrentProcess(), NULL, exe_name, NULL, 0, 0);
				SymbolsAvailable = true;
			}
		}
	}
}







/***********************************************************************************************
 * Lookup_Symbol -- Get the symbol for a given code address                                    *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Address of code to get symbol for                                                 *
 *           Ptr to buffer to return symbol in                                                 *
 *           Reference to int to return displacement                                           *
 *                                                                                             *
 * OUTPUT:   True if symbol found                                                              *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   6/12/2001 4:47PM ST : Created                                                             *
 *=============================================================================================*/
bool Lookup_Symbol(void *code_ptr, char *symbol, int &displacement)
{
	char symbol_struct_buf[1024];
	IMAGEHLP_SYMBOL64 *symbol_struct_ptr = (IMAGEHLP_SYMBOL64 *)symbol_struct_buf;

	displacement = 0;
	*symbol = '\0';

	if (!SymbolsAvailable) {
		return(false);
	}

	memset(symbol_struct_ptr, 0, sizeof(symbol_struct_buf));
	symbol_struct_ptr->SizeOfStruct = sizeof(IMAGEHLP_SYMBOL64);
	symbol_struct_ptr->MaxNameLength = sizeof(symbol_struct_buf) - sizeof(IMAGEHLP_SYMBOL64);
	symbol_struct_ptr->Size = 0;
	symbol_struct_ptr->Address = (DWORD64)(ULONG_PTR)code_ptr;

	DWORD64 disp64 = 0;
	if (SymGetSymFromAddr64(GetCurrentProcess(), (DWORD64)(ULONG_PTR)code_ptr, &disp64, symbol_struct_ptr)) {
		displacement = (int)disp64;
		strcpy(symbol, symbol_struct_ptr->Name);
		return(true);
	}
	return(false);
}




/***********************************************************************************************
 * Stack_Walk -- Walk the stack and get the last n return addresses                            *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Ptr to return address list                                                        *
 *           Number of return addresses to fetch                                               *
 *           Ptr to optional context. NULL means use current                                   *
 *                                                                                             *
 * OUTPUT:   Number of return addresses found                                                  *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   6/12/2001 11:57AM ST : Created                                                            *
 *=============================================================================================*/
int Stack_Walk(DWORD64 *return_addresses, int num_addresses, CONTEXT *context)
{
	static HINSTANCE _imagehelp = (HINSTANCE) -1;

	/*
	** If this is the first time through then fix up the imagehelp function pointers since imagehlp.dll
	** can't be statically linked.
	*/
	if (ImageHelp == (HINSTANCE)-1) {
		Load_Image_Helper();
	}

	/*
	** If there is no debug support .dll available then we can't walk the stack.
	*/
	if (ImageHelp == NULL) {
		return(0);
	}

/*
** Set up the stack frame structure for the start point of the stack walk (i.e. here).
*/
	STACKFRAME64 stack_frame;
	memset(&stack_frame, 0, sizeof(stack_frame));

	CONTEXT capture_ctx;
	RtlCaptureContext(&capture_ctx);

	stack_frame.AddrPC.Mode = AddrModeFlat;
	stack_frame.AddrPC.Offset = capture_ctx.Rip;
	stack_frame.AddrStack.Mode = AddrModeFlat;
	stack_frame.AddrStack.Offset = capture_ctx.Rsp;
	stack_frame.AddrFrame.Mode = AddrModeFlat;
	stack_frame.AddrFrame.Offset = capture_ctx.Rbp;

	/*
	** Use the context struct if it was provided.
	*/
	if (context) {
		stack_frame.AddrPC.Offset = context->Rip;
		stack_frame.AddrStack.Offset = context->Rsp;
		stack_frame.AddrFrame.Offset = context->Rbp;
	}

	int pointer_index = 0;

	/*
	** Walk the stack by the requested number of return address iterations.
	*/
	for (int i = 0; i < num_addresses + 1; i++) {
		if (StackWalk64(IMAGE_FILE_MACHINE_AMD64, GetCurrentProcess(), GetCurrentThread(), &stack_frame, NULL, NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL)) {

			/*
			** First result will always be the return address we were called from.
			*/
			if (i==0 && context == NULL) {
				continue;
			}
			DWORD64 return_address = stack_frame.AddrReturn.Offset;
			return_addresses[pointer_index++] = return_address;
		} else {
			break;
		}
	}

	return(pointer_index);
}



void Register_Application_Exception_Callback(void (*app_callback)(void))
{
	AppCallback = app_callback;
}

void Register_Application_Version_Callback(char *(*app_ver_callback)(void))
{
	AppVersionCallback = app_ver_callback;
}



void Set_Exit_On_Exception(bool set)
{
	ExitOnException = true;
}

bool Is_Trying_To_Exit(void)
{
	return(TryingToExit);
}




#endif	//_MSC_VER




