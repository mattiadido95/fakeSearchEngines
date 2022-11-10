//#include <windows.h>
//#include "sys/types.h"
//
//unsigned long long getTotalSystemMemory()
//{
//
//    MEMORYSTATUSEX status;
//    status.dwLength = sizeof(status);
//    GlobalMemoryStatusEx(&status);
//    DWORDLONG physMemUsed = status.ullTotalPhys - status.ullAvailPhys;
//    return status.ullTotalPhys- status.ullAvailPhys;
//}