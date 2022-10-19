//g++ -o main.exe main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include "preprocessing.h"

using namespace std;

int main(){
    ifstream filein("../data/collection.tsv");
    int c;
    c = 0;

    for (string doc; getline(filein, doc); ) 
    {
        Preprocessing p(doc);
        c ++;
        if (c == 5)
            break;
    }
    
    filein.close();
    
    //preprocessing
    return 0;
}