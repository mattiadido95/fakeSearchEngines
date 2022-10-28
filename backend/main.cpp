// g++ -o main.out main.cpp && ./main.out
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include "preprocessing.h"
#include "utility/FileManager.h"

using namespace std;

int main()
{
    // start preprocessing
    Preprocessing p("../data/collection.tsv");

    FileManager fm("../data/collection.tsv");
    string result = fm.readLine();
    cout << endl
         << "print first document ->" << endl
         << result << endl;

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