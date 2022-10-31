#include "preprocessing.h"
#include "PorterStemming.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include <map>


using namespace std;

vector<string> Preprocessing::tokenization(string doc){  
    vector<string> words;
      
    transform(doc.begin(), doc.end(), doc.begin(), ::tolower);  
    
    regex re("\\s+|\\!|\"|\\#|\\$|\\%|\\&|\\'|\\(|\\)|\\*|\\+|\\,|\\-|\\.|\\/|\\:|\\;|\\<|\\=|\\>|\\|\\?|\\@|\\[|\\]|\\^|\\_|\\`|\\{|\\||\\}|\\~");
    sregex_token_iterator it(doc.begin(), doc.end(), re, -1);
    sregex_token_iterator reg_end;
    
    for (; it != reg_end; ++it) {
        if (it->str() == "")
                continue;
        words.push_back(it->str());
    }
    
    //for(int i = 0; i < words.size(); i++)
    //        cout << words[i] << '\n';
    return words;

}
map<string, int>Preprocessing::removeDuplicate(vector<string> vocabulary){
    map<string, int> m;
    for(int i = 0; i< vocabulary.size(); i++)
    {
          m.insert(pair<string, int>(vocabulary[i], 0));
    }
    return m;
}
vector<string> Preprocessing::removeWordstop(vector<string> words)
{
    int c;
    bool check= false;
    vector<string> words_nostw;
    for(int i = 0; i< words.size(); i++){
        string ciao = words[44];
        ifstream filein("../../data/stop_words_english.txt");
        for (string wordstop; getline(filein, wordstop);) {
            if (wordstop.compare(words[i]) == 0)
                check = true;
        }
        filein.close();
        if (check == false)
            words_nostw.push_back(words[i]);
        check=false;
    }
    for(int i = 0; i<words_nostw.size(); i++)
        cout<<words.size()<<" "<<words_nostw.size()<<" "<< words_nostw[i]<<endl;

    return words_nostw;

}

Preprocessing::Preprocessing(string path){
    vector<string> words;
    vector<string> words2;
    vector<string> support;
    vector<string> wordsdocs; 
    map<string, int> cleanVocabulary; 
    ifstream filein(path);
    int c;
    
    for (string doc; getline(filein, doc); ) 
    {
        words= tokenization(doc);
        
        string id = words[0];
        words.erase(words.begin());
        words = removeWordstop(words);
        words2 = Preprocessing::porterStemming(words);
        for(int i = 0; i< words.size(); i++)
            cout<<words[i]<<" "<<words2[i]<<endl;
        break;
        support.clear();
        support.reserve( words.size() + wordsdocs.size() );
        support.insert( support.end(), wordsdocs.begin(), wordsdocs.end());
        support.insert( support.end(), words.begin(), words.end());
        wordsdocs= support;   
        c++;
        if (c == 5 )
            break;

        
    }
        filein.close();

   
    //stopword
    //lemmatizzazione
    //duplicate
        cleanVocabulary = removeDuplicate(wordsdocs);
    
    
}
