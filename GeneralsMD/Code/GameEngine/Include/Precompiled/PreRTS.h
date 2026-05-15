#ifndef __PRERTS_H__
#define __PRERTS_H__

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <atlbase.h>
#endif

#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <fstream>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#include <imagehlp.h>
#include <mmsystem.h>
#include <objbase.h>
#include <process.h>
#include <shellapi.h>
#include <shlobj.h>
#include <wininet.h>
#endif

// On non-Windows, provide compatible alternatives
#ifndef _WIN32
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#define _chdir chdir
#define _getcwd getcwd
#endif

#include "Lib/Basetype.h"
#include "Common/STLTypedefs.h"
#include "Common/Errors.h"
#include "Common/Debug.h"
#include "Common/AsciiString.h"
#include "Common/SubsystemInterface.h"
#include "Common/GameCommon.h"
#include "Common/GameMemory.h"
#include "Common/GameType.h"
#include "Common/GlobalData.h"
#include "Common/INI.h"
#include "Common/KindOf.h"
#include "Common/DisabledTypes.h"
#include "Common/NameKeyGenerator.h"
#include "GameClient/ClientRandomValue.h"
#include "GameLogic/LogicRandomValue.h"
#include "Common/ObjectStatusTypes.h"
#include "Common/Thing.h"
#include "Common/UnicodeString.h"

#endif
