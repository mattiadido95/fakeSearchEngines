#include "preprocessing.h"
#include <string>
#include <iostream>

using namespace std;

vector<string> Preprocessing::stopwords()
{
    string lineread;
    ifstream sw("stopwords.txt");
    vector<string> stopwords;
    while (sw.good())
    {
        getline(sw, lineread);
        stopwords.push_back(lineread);
    }
    sw.close();

    return stopwords;
}