//#include <windows.h>
#include <unistd.h>

unsigned long long getTotalSystemMemory()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

//unsigned long long getTotalSystemMemory()
//{
//    MEMORYSTATUSEX status;
//    status.dwLength = sizeof(status);
//    GlobalMemoryStatusEx(&status);
//    return status.ullTotalPhys;
//}