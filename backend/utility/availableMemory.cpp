//#include <windows.h>
//#include "sys/types.h"
#include <availableMemory.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int parseLine(char *line) {
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char *p = line;
    while (*p < '0' || *p > '9') p++;
    line[i - 3] = '\0';
    i = atoi(p);
    return i;
}

int getValue() { //Note: this value is in KB!
    FILE *file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result / 1024;
}

unsigned long long getTotalSystemMemory() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

//unsigned long long getTotalSystemMemory()
//{
//
//    MEMORYSTATUSEX status;
//    status.dwLength = sizeof(status);
//    GlobalMemoryStatusEx(&status);
//    DWORDLONG physMemUsed = status.ullTotalPhys - status.ullAvailPhys;
//    return status.ullTotalPhys- status.ullAvailPhys;
//}