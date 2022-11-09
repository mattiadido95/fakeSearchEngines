#include "preprocessing.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper
#include <map>
#include "utility/utility.h"
#include "index/Index.h"

using namespace std;

vector<string> Preprocessing::tokenization(string doc){  
    vector<string> words;
      
    transform(doc.begin(), doc.end(), doc.begin(), ::tolower);  
    /*
     * removed |\\_ because on it causes
     * libc++abi: terminating with uncaught exception of type
     * std::__1::regex_error: The expression contained an
     * invalid escaped character, or a trailing escape.
     */
    regex re("\\s+|\\!|\"|\\#|\\$|\\%|\\&|\\'|\\(|\\)|\\*|\\+|"
             "\\,|\\-|\\.|\\/|\\:|\\;|\\<|\\=|\\>|\\|\\?|\\@|\\[|"
             "\\]|\\^|\\`|\\{|\\||\\}|\\~");
    sregex_token_iterator it(doc.begin(), doc.end(), re, -1);
    sregex_token_iterator reg_end;
    
    for (; it != reg_end; ++it) {
        if (it->str() == "")
                continue;
        words.push_back(it->str());
    }


    return words;

}
vector<string> Preprocessing::getStopwords() {
    vector<string> stopwords;
    ifstream file("../../data/stop_words_english.txt");
    string line;
    while (getline(file, line)) {
        stopwords.push_back(line);
    }
    return stopwords;
}

vector<string> Preprocessing::removeWordstop(vector<string> words) {
    //  get stopwords list
    //cout << "- start import stopword list ..." << endl;
    vector<string> stopwords = getStopwords();
    utility utility;
    //cout << "   -> number of stopword imported " << stopwords.size() << endl;

    //      create for loop to remove stopwords from tokens list
    //cout << "- start find stopword into tokens ..." << endl;
    vector<int> index_list; // list of index to remove from tokens list that match with stopwords
    std::sort(words.begin(), words.end()); // sort word array to implement binary search
    for (vector<string>::iterator s = stopwords.begin(); s != stopwords.end(); s++) {
        // cout << "   -> find stopword: " << *s << ": ";

        int res = utility.binary_search(words, *s, words.size());
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

    return words;
}

void Preprocessing::build_index(string docid, vector<string> words){
    this->index->addDocIndex(docid,words.size());
    for(int i = 0; i< words.size(); i++){
        this->index->addLexicon(docid,words[i]);

    }
}
//void Preprocessing::build_index(string id, vector<string> words){
//    map<string,int> posting_list;
//    string score_sting;
//    int frequency;
//    for(int i = 0; i< words.size(); i++)
//    {
//        if (this->index.count(words[i])>0) //check if a single word exists in vocabulary
//        {
//            //extract the postlisting of the word i-th
//            auto it = this->index.find(words[i]);
//            posting_list = it->second;
//
//            //from posting list of the word j-th I take all (docid, frequency)
//            if (posting_list.count(id)>0) {
//                //if I enter in the "if" I report it
//                //take the frequency and increasing the value of 1
//                frequency = posting_list.find(id)->second++;
//                //remove from posting_list old posting
//                posting_list.erase(id);
//                //delete all row of map
//                this->index.erase(it);
//                //update new value in map
//                posting_list.insert(pair<string,int>(id, frequency));
//                this->index.insert(pair<string, map<string,int>>(words[i], posting_list));
//                posting_list.clear();
//                break;
//            }
//        }else{
//            //it means that the word[i] exists but the document has not yet been added to the postilisting of it
//            posting_list.insert(pair<string,int>(id, 1));
//
//            this->index.insert(pair<string, map<string,int>>(words[i], posting_list));
//            posting_list.clear();
//        }
//    }
//    return;
//}

Preprocessing::Preprocessing(string path, Index * index){
    this->index=index;
    vector<string> words;
    vector<string> words2;
    vector<string> support;
    vector<string> wordsdocs;
    ifstream filein(path);
    int c=0;
    
    for (string doc; getline(filein, doc); ) 
    {
        words= tokenization(doc);
        
        string id = words[0];
        words.erase(words.begin());
        //stopword
        words = removeWordstop(words);
        //stemming
        words = porterStemming(words);
        //index
        //1. add info of the document
        build_index(id, words);




        c++;
        if (c == 1000 ) {
            for (auto ii = this->index->lexicon.begin(); ii != this->index->lexicon.end(); ++ii) {
                cout << ii->first << "---> "<<"cf: "<< ii->second.cf<<" df: "<< ii->second.df<<endl;
                for(int i = 0; i< static_cast<vector<post>>(*ii->second.posting_list).size(); i++){
                    cout<<"     id:"<<static_cast<vector<post>>(*ii->second.posting_list)[i].id<<" tf: "<< static_cast<vector<post>>(*ii->second.posting_list)[i].tf<<endl;
                }
            }
//            for (auto ii = this->index.begin(); ii != this->index.end(); ++ii) {
//                cout << ii->first << ": ";
//                map<string,int> inVect = ii->second;
//                for (auto tt = inVect.begin(); tt != inVect.end(); ++tt){
//
//                    cout << "(" << tt->first << "," << tt->second << "),";
//                }
//                cout << endl;
//            }
            break;
        }

        
    }
        filein.close();

   


    //duplicate

    
    
}


