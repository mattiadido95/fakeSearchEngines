//g++ -o main.out -I ./utilityold *.cpp utilityold/*.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include "preprocessing.h"
#include "utility/FileManager.h"
#include "utility/availableMemory.cpp"
#include "index/Index.h"
//#include "psapi.h"
//#include "windows.h"
#include <chrono>

using namespace std;

int main() {
    // start preprocessing
//    unsigned long long Memory = getTotalSystemMemory();
//    cout<<Memory<<endl;

    auto start = chrono::steady_clock::now();
    Index index;

    Preprocessing p("../../data/collection.tsv", i);
//    Memory = getTotalSystemMemory();
//    cout<<"Finisch memory:  "<<Memory<<endl;
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in seconds: "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";
    return 0;
}