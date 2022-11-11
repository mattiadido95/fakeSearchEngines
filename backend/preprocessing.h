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
    std::vector<string> tokenization(string);
    std::vector<string> getStopwords();
    std::vector<string> removeWordstop(std::vector<string>);// stopwords
    std::vector<string> porterStemming(std::vector<string>);// stemming
    int build_index(string, std::vector<string>);// remove duplicate

public:
    Preprocessing(string, Index *);
};