// g++ -o main.out main.cpp && ./main.out
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
    // start preprocessing
    Preprocessing p("../data/collection.tsv");

    // string stopwords[] = {"Geeks", "For", "GeeksForGeek"};
    // int size = sizeof(stopwords) / sizeof(stopwords[0]);
    // sort(stopwords, stopwords + size);
    // string str = "For";

    // if (binary_search(stopwords, stopwords + size, str))
    // {
    //     cout << "found" << endl;
    // }
    // else
    // {
    //     cout << "not found" << endl;
    // }

    return 0;
}