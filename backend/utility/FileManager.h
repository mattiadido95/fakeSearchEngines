#ifndef BACKEND_FILEMANAGER_H
#define BACKEND_FILEMANAGER_H

#include<fstream>
#include<string>
#include<vector>
#include <map>
using namespace std;

class FileManager{
    private:
        string path;
        ifstream inFile;
        ofstream outFile;
        bool write;
    public:
        FileManager(string,bool);
        vector<string> readFile();
        string readLine();
        void writeLine(int, vector<string>);
        ~FileManager();
};

#endif //BACKEND_UTILITY_H
