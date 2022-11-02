//g++ -o main.exe main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include "preprocessing.h"
#include "utility/FileManager.h"

using namespace std;

int main() {
    // start preprocessing
    Preprocessing p("../../data/collection.tsv");

    FileManager fm("../data/collection.tsv");
    string result = fm.readLine();
    cout << endl
         << "print first document ->" << endl
         << result << endl;
    return 0;
}