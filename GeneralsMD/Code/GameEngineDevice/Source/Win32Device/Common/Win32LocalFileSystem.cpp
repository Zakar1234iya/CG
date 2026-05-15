#include "Win32LocalFileSystem.h"
#include <windows.h>
#include <cstring>

void Win32LocalFileSystem::getFileListInDirectory(const AsciiString& currentDirectory, std::set<AsciiString>& filenameList)
{
	WIN32_FIND_DATA findData;
	HANDLE fileHandle;
	bool done;
	AsciiString search = currentDirectory + "*";

	fileHandle = FindFirstFile(search.c_str(), &findData);
	done = (fileHandle == INVALID_HANDLE_VALUE);

	int entryCount = 0;
	const int LOG_INTERVAL = 5000;  // Log every 5000 entries to avoid debug spam

	while (!done)	{
		if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
				(strcmp(findData.cFileName, ".") && strcmp(findData.cFileName, ".."))) {
			AsciiString newFilename = currentDirectory + findData.cFileName;

			if (filenameList.find(newFilename) == filenameList.end()) {
				filenameList.insert(newFilename);
			}
			entryCount++;
#ifdef _DEBUG
			// Throttle logging to every LOG_INTERVAL entries to prevent 45-min debug startup
			if (entryCount % LOG_INTERVAL == 0) {
				DEBUG_LOG(("Win32LocalFileSystem::getFileListInDirectory - processed %d files in %s\\n", entryCount, search.c_str()));
			}
#endif
		}

		done = (FindNextFile(fileHandle, &findData) == 0);
	}

	FindClose(fileHandle);
}