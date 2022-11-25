#ifndef BACKEND_FILEMANAGER_H
#define BACKEND_FILEMANAGER_H

#include<fstream>
#include<string>
#include<vector>
#include <map>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stxxl.h>

using namespace std;

class FileManager{
    private:
        string path;
        string mode;

        ifstream inFile;
        ofstream outFile;

        char* file_mem;
        int fd;
        struct stat sb;
    public:
        FileManager(string,string);
        vector<string> readFile();
        string readLine();
        void writeLine(int, vector<string>);
        void writeLine(string);
        ~FileManager();
};

#endif //BACKEND_UTILITY_H
