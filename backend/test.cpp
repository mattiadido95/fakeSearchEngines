#include <set>
//g++ -o main.exe main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include "preprocessing.h"

using namespace std;
int main()
{
    std::string aString = "abbc";

    //create set from std::string
    std::set<char> mySet( aString.begin() , aString.end() );
    
    std::cout<< mySet;
    return 0;
}