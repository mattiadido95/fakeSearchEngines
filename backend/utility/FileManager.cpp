#include <iostream>
#include "FileManager.h"

FileManager::FileManager(string path, string mode) {
    path = path;
    mode = mode;
    if(mode.compare("write") == 0)
        outFile.open(path, fstream::out);
    else if(mode.compare("read") == 0)
        inFile.open(path, fstream::in);
    else if(mode.compare("append") == 0)
        outFile.open(path, fstream::app);
    else if(mode.compare("memory") == 0) {
        fd = open(path.c_str(), O_RDONLY, S_IRUSR | S_IWUSR);
        if(fstat(fd,&sb) == -1){
            perror("couldn't get file size\n");
        }
        file_mem = (char*) mmap(NULL,sb.st_size,PROT_READ, MAP_SHARED,fd,0);
    }else
        perror("Error in FileManager constructor\n");
}

vector<string> FileManager::readFile() {
    vector<string> buffer;
    for (string line; getline(inFile, line);) {
        buffer.push_back(line);
    }
    return buffer;
}

string FileManager::readLine() {
    string line = "";
    return (getline(inFile, line)) ? line : "";
}

void FileManager::writeLine(int docId, vector<string> s){
    string result = to_string(docId) + " ";
    for(int i = 0; i < s.size(); i++){
        result += s[i] + " ";
    }
    outFile << result << endl;
}

void FileManager::writeLine(string s){
    outFile << s << endl;
}

string FileManager::findPosition(string term,stxxl::vector<string>&dictionary){
    string fetchedTerm = "";
    string indexPos = "";
    bool found = false;
    bool termFetched = false;
    //file struct -> term pos\n
    for(int i = 0; i < dictionary.size(); i++){
        //look for term
        if(term.compare(dictionary[i])==0) {
            found = true;
            indexPos = to_string(i);
        }


    }
    return indexPos;
}

FileManager::~FileManager() {
    if(mode.compare("write") == 0 || mode.compare("append") == 0)
        outFile.close();
    if(mode.compare("read") == 0)
        inFile.close();
    if(mode.compare("memory") == 0) {
        munmap(file_mem,sb.st_size);
        close(fd);
        file_mem = NULL;
    }
}