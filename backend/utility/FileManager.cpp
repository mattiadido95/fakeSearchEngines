#include <iostream>
#include "FileManager.h"

FileManager::FileManager(string path, bool write) {
    path = path;
    write = write;
    if(write)
        outFile.open(path, fstream::out);
    else
        inFile.open(path, fstream::in);
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
    string result = to_string(docId) + "\t";
    for(int i = 0; i < s.size(); i++){
        result += s[i] + " ";
    }
    outFile << result << endl;
}

FileManager::~FileManager() {
    if(write)
        outFile.close();
    else
        inFile.close();
}