#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Preprocessing
{
public:
    vector<string> tokenization();
    vector<string> stopwords();
    vector<string> stemming();
};