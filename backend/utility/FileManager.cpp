#include <iostream>
#include "FileManager.h"

FileManager::FileManager(string path) {
    path = path;
    file.open(path, fstream::in);
}

vector<string> FileManager::readFile() {
    vector<string> buffer;
    for (string line; getline(file, line);) {
        buffer.push_back(line);
    }
    return buffer;
}

string FileManager::readLine() {
    string line = "";
    return (getline(file, line)) ? line : "";
}

FileManager::~FileManager() {
    file.close();
}