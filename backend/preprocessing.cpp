#include "preprocessing.h"
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper

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
Preprocessing::Preprocessing(string doc){
    vector<string> words;
    words = tokenization(doc);    
}
