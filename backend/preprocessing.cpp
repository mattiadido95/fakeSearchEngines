#include "preprocessing.h"
// #include "PorterStemming.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper

using namespace std;

vector<string> Preprocessing::tokenization(string doc)
{
    vector<string> words;

    transform(doc.begin(), doc.end(), doc.begin(), ::tolower);

    regex re("\\s+|\\!|\"|\\#|\\$|\\%|\\&|\\'|\\(|\\)|\\*|\\+|\\,|\\-|\\.|\\/|\\:|\\;|\\<|\\=|\\>|\\|\\?|\\@|\\[|\\]|\\^|\\_|\\`|\\{|\\||\\}|\\~");
    sregex_token_iterator it(doc.begin(), doc.end(), re, -1);
    sregex_token_iterator reg_end;

    for (; it != reg_end; ++it)
    {
        if (it->str() == "")
            continue;
        words.push_back(it->str());
    }

    // for(int i = 0; i < words.size(); i++)
    //         cout << words[i] << '\n';

    return words;
}

vector<string> Preprocessing::getStopwords()
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

Preprocessing::Preprocessing(string path)
{
    vector<string> words;
    vector<string> support;
    vector<string> wordsdocs;
    ifstream filein(path);
    int c;

    for (string doc; getline(filein, doc);)
    {
        words = tokenization(doc);
        support.reserve(words.size() + wordsdocs.size());
        support.insert(support.end(), wordsdocs.begin(), wordsdocs.end());
        support.insert(support.end(), words.begin(), words.end());
        wordsdocs = support;

        if (c > 2)
        {
            break;
        }
        c++;
    }

    filein.close();

    // get string list tokenized
    // vector<string> tokens = p.getTokens();

    // get stopwords list
    vector<string> stopwords = getStopwords();

    // create for loop to remove stopwords from tokens list
}
