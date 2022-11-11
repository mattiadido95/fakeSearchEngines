#include <iostream>
#include "FileManager.h"

FileManager::FileManager(string path,bool write) {
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

FileManager::~FileManager() {
    if(write)
        outFile.close();
    else
        inFile.close();
}