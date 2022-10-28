//g++ -o main.out -I ./utility *.cpp utility/*.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include "preprocessing.h"
#include "utility/FileManager.h"

using namespace std;

int main(){
    cout << "Ciao" << endl;
    FileManager fm("../stop.txt");
    vector<string> res = fm.readFile();
    string result = fm.readLine();
    cout << result << endl;
    result = fm.readLine();
    cout << result << endl;
    //preprocessing
    return 0;
}