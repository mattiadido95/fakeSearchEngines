#include "preprocessing.h"
 //#include "PorterStemming.cpp"
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
        words.push_back(it->str()+"\0");
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
vector<string> Preprocessing::remuveWordstop(vector<string> words)
{
    ifstream filein("../data/stop_words_english.txt");
    int c;
    vector<string> words_nostw;
    string ciao = "able";
    for (string wordstop; getline(filein, wordstop); ) 
    {
        
        for(int i = 0; i< words.size(); i++){
            cout<<wordstop[8]<<endl;
            if (ciao.compare("able")== 0){
                cout<<"sono dentro"<<endl;
                words_nostw.push_back(words[i]);}
            break;
        }
        break;
    }
    for(int i = 0; i<words_nostw.size(); i++)
        cout<<words_nostw[i]<<endl;    
    return words_nostw;

}

Preprocessing::Preprocessing(string path){
    vector<string> words;
    vector<string> support;
    vector<string> wordsdocs; 
    map<string, int> cleanVocabulary; 
    ifstream filein(path);
    int c;
    
    for (string doc; getline(filein, doc); ) 
    {
        words= tokenization(doc);
        words = remuveWordstop(words);
        string id = words[0];
        words.erase(words.begin());

       
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
