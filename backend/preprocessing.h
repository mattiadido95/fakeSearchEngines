#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include <regex>
#include "utility/utility.h"
#include "utility/FileManager.h"
using namespace std;

class Preprocessing {
private:
    utility util;
    FileManager* docsFile;
    FileManager* stopwordsFile;
    FileManager* outputFile;
    std::vector<string> tokenization(string);
    std::vector<string> removeStopword(std::vector<string>);// stopwords
    std::vector<string> porterStemming(std::vector<string>);// stemming
public:
    Preprocessing(string);
};