#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>



using namespace std;

class Preprocessing{
    private:
    vector<string> tokenization(string);

    // stopwords();
    vector<string> removeWordstop(vector<string>);



    // stemming();
    vector<string> porterStemming(vector<string>);


    // remove duplicate
    map<string, int> removeDuplicate(vector<string>);
    
    public:
    Preprocessing(string);
};