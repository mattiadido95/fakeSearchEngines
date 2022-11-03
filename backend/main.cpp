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

int main() {
    // start preprocessing
    Preprocessing p("../../data/collection.tsv");
    return 0;
}