#include "preprocessing.h"
#include <string>
#include <iostream>

using namespace std;

vector<string> Preprocessing::stopwords()
{
    string lineread;
    ifstream sw("stopwords.txt"); // taken from https://gist.github.com/sebleier/554280
    vector<string> stopwords;
    while (sw.good())
    {
        getline(sw, lineread);
        stopwords.push_back(lineread);
    }
    sw.close();

    // sort stopword for binary search

    return stopwords;
}