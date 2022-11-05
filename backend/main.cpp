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

using namespace std;

int main() {
    // start preprocessing
    unsigned long long Memory = getTotalSystemMemory();
    cout<<Memory<<endl;
    Preprocessing p("../../data/collection.tsv");
    return 0;
}