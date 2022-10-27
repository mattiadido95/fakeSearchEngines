#include "FileManager.h"

FileManager(string path){
    this.path = path
    this.file = filein(path);
}
vector<string> FileManager::readFile(){
    vector<string> buffer;
    for (string line; getline(filein, line); ) {
        buffer.push_back(line);
    }
}
string * FileManager::readLine(){
    return (getline(filein, line) == false) ? "" : line;
}