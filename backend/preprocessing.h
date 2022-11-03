#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Preprocessing{
    private:
    map<string, map<string,int>> index;
    vector<string> tokenization(string);

    vector<string> getStopwords();

    // stopwords();
    vector<string> removeWordstop(vector<string>);
    // stemming();
    vector<string> porterStemming(vector<string>);
    // remove duplicate
    void build_index( string,vector<string>);

    public:
    Preprocessing(string);
};