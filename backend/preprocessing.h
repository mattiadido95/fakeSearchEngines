#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include "utility/utility.h"
#include "index/Index.h"
using namespace std;

class Preprocessing{
    private:
   // map<string, map<string,int>> index;
    Index* index;
    vector<string> tokenization(string);
    vector<string> getStopwords();

    // stopwords();
    vector<string> removeWordstop(vector<string>);
    // stemming();
    vector<string> porterStemming(vector<string>);
    // remove duplicate
    int build_index( string,vector<string>);

    public:
    Preprocessing(string,Index*);



};