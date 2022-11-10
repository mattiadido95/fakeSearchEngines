#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include "utility/utility.h"
#include "index/Index.h"

using namespace std;

class Preprocessing {
private:

    Index *index;// map<string, map<string,int>> index;
    vector<string> tokenization(string);
    vector<string> getStopwords();
    vector<string> removeWordstop(vector<string>);// stopwords
    vector<string> porterStemming(vector<string>);// stemming
    int build_index(string, vector<string>);// remove duplicate

public:
    Preprocessing(string, Index *);
};