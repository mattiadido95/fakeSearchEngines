#include "preprocessing.h"
//#include "PorterStemming.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include <map>
#include "utility/utility.h"

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

map<string, int> Preprocessing::removeDuplicate(vector<string> vocabulary)
{
    map<string, int> m;
    for (int i = 0; i < vocabulary.size(); i++)
    {
        m.insert(pair<string, int>(vocabulary[i], 0));
    }
    return m;
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
        // cout << lineread << endl;
    }

    sw.close();

    return stopwords;
}

Preprocessing::Preprocessing(string path)
{
    vector<string> words;
    vector<string> support;
    vector<string> wordsdocs;
    map<string, int> cleanVocabulary;
    ifstream filein(path);
    int c = 0;

    cout << "- start import documents ..." << endl;
    for (string doc; getline(filein, doc);)
    {
        cout << "   -> start import documents n." << c << endl;
        words = tokenization(doc);
        support.reserve(words.size() + wordsdocs.size());
        support.insert(support.end(), wordsdocs.begin(), wordsdocs.end());
        support.insert(support.end(), words.begin(), words.end());
        wordsdocs = support;
        c++;
        if (c == 3)
        {
            break;
        }
    }
    filein.close();

    // tokens list
    cout << "   -> number of stopword imported " << words.size() << endl;

    // lemmatizzazione

    // duplicate
    cout << "- start cleaning vocabulary ..." << endl;
    cleanVocabulary = removeDuplicate(wordsdocs);

    // get stopwords list
    cout << "- start import stopword list ..." << endl;
    vector<string> stopwords = getStopwords();
    cout << "   -> number of stopword imported " << stopwords.size() << endl;

    // // create for loop to remove stopwords from tokens list
    // string *tokens_array = vector_to_array(words);
    // show_array(tokens_array, words.size());
    // for (vector<string>::iterator w = stopwords.begin(); w != stopwords.end(); w++)
    // {
    //     cout << "- find word: " << *w << endl;
    //     cout << binary_search(tokens_array, *w, words.size()) << endl;
    // }

    my_search(stopwords, words);
}
