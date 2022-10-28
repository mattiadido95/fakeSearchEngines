#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Preprocessing
{
private:
    vector<string> tokenization(string);
    vector<string> getStopwords();
    // stopwords();
    // stemming();
    // remove duplicate
    map<string, int> removeDuplicate(vector<string>);

public:
    Preprocessing(string);
};