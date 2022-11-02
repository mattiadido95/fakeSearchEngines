#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Preprocessing{
    private:
    map<string, vector<vector<string>>> index;
    vector<string> tokenization(string);
    // stopwords();
    vector<string> removeWordstop(vector<string>);
    // stemming();
    vector<string> porterStemming(vector<string>);
    // remove duplicate
    void removeDuplicate( string,vector<string>);

    public:
    Preprocessing(string);
};