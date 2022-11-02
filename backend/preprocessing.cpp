#include "preprocessing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include <map>
#include "utility/utility.h"
#include "PorterStemming.cpp"

using namespace std;

vector<string> Preprocessing::tokenization(string doc) {
    vector<string> words;

    transform(doc.begin(), doc.end(), doc.begin(), ::tolower);

    regex re(
            "\\s+|\\!|\"|\\#|\\$|\\%|\\&|\\'|\\(|\\)|\\*|\\+|\\,|\\-|\\.|\\/|\\:|\\;|\\<|\\=|\\>|\\|\\?|\\@|\\[|\\]|\\^|\\_|\\`|\\{|\\||\\}|\\~");
    sregex_token_iterator it(doc.begin(), doc.end(), re, -1);
    sregex_token_iterator reg_end;

    for (; it != reg_end; ++it) {
        if (it->str() == "")
            continue;
        words.push_back(it->str());
    }


    return words;

}

map<string, int> Preprocessing::removeDuplicate(vector<string> vocabulary) {
    map<string, int> m;
    for (int i = 0; i < vocabulary.size(); i++) {
        m.insert(pair<string, int>(vocabulary[i], 0));
    }
    return m;
}

vector<string> Preprocessing::removeWordstop(vector<string> words) {
    vector<string> wordstops;
    bool check = false;
    vector<string> words_nostw;

    ifstream filein("../../data/stop_words_english.txt");
    for (string wordstop; getline(filein, wordstop);) {
        wordstops.push_back(wordstop);
    }
    filein.close();

    for (int i = 0; i < words.size(); i++) {
        string ciao = words[44];
        for (int j = 0; j < wordstops.size(); j++) {
            if (wordstops[j].compare(words[i]) == 0)
                check = true;
        }
        if (check == false)
            words_nostw.push_back(words[i]);
        check = false;
    }
    return words_nostw;
}

vector<string> Preprocessing::getStopwords() {
    vector<string> stopwords;
    ifstream file("../backend/stopwords.txt");
    string line;
    while (std::getline(file, line)) {
        stopwords.push_back(line);
    }
    return stopwords;
}

Preprocessing::Preprocessing(string path) {
    vector<string> words;
    vector<string> words2;
    vector<string> support;
    vector<string> wordsdocs;
    map<string, int> cleanVocabulary;
    ifstream filein(path);
    int c;

    //  get stopwords list
    cout << "- start import stopword list ..." << endl;
    vector<string> stopwords = getStopwords();
    cout << "   -> number of stopword imported " << stopwords.size() << endl;

    cout << "- start import documents ..." << endl;
    for (string doc; getline(filein, doc);) {
        cout << "   -> start import documents n." << c << endl;
        words = tokenization(doc);
        string id = words[0];
        words.erase(words.begin());

//      words = removeWordstop(words); // salvo's methods

//      create for loop to remove stopwords from tokens list
        cout << "- start find stopword into tokens ..." << endl;
        vector<int> index_list; // list of index to remove from tokens list that match with stopwords
        std::sort(words.begin(), words.end()); // sort word array to implement binary search
        for (vector<string>::iterator s = stopwords.begin(); s != stopwords.end(); s++) {
            cout << "   -> find stopword: " << *s << ": ";
            int res = binary_search(words, *s, words.size());
            if (res != -1) {
//              cout << "FOUND" << endl;
                index_list.push_back(res);
            }
//            else {
//              cout << "NOT FOUND" << endl;
//            }
        }

//  delete stopwords from tokens vector
        for (int index: index_list) {
            words.erase(words.begin() + index); // TODO -> controllare complessita erase() - probabilmente o(n)
        }

        cout << "   -> start stemming" << endl;
        words2 = porterStemming(words); // stemming phase
        for (int i = 0; i < words.size(); i++)
            cout << "       token iniziale -> " << words[i] << "   token con stemming -> " << words2[i] << endl;

        //break; // TODO -> chiedere a salvo perche breakka qui

        support.clear();
        support.reserve(words.size() + wordsdocs.size());
        support.insert(support.end(), wordsdocs.begin(), wordsdocs.end());
        support.insert(support.end(), words.begin(), words.end());
        wordsdocs = support;
        c++;
        if (c == 5)
            break;
    }
    filein.close();

//  tokens list
    cout << "   -> number of stopword imported " << words.size() << endl;


//  remove duplicates
    cout << "- start cleaning vocabulary ..." << endl;
    cleanVocabulary = removeDuplicate(wordsdocs);


}
