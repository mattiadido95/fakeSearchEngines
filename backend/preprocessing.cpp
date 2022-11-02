#include "preprocessing.h"

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

vector<string> Preprocessing::removeWordstop(vector<string> words)
{
    vector<string> wordstops;
    bool check= false;
    vector<string> words_nostw;

    ifstream filein("../../data/stop_words_english.txt");
    for (string wordstop; getline(filein, wordstop);) {
        wordstops.push_back(wordstop);
    }
    filein.close();

    for(int i = 0; i< words.size(); i++){
        for(int j = 0; j< wordstops.size(); j++){
            if (wordstops[j].compare(words[i]) == 0)
                check = true;
        }
        if (check == false)
            words_nostw.push_back(words[i]);
        check=false;
    }


    return words_nostw;

}
void Preprocessing::removeDuplicate(string id, vector<string> words){
    vector<string> id_score;vector<vector<string>> posting_list;
    string score_sting;
    bool check;
    int string_int;
    for(int i = 0; i< words.size(); i++)
    {
        check = false;
        if (this->index.count(words[i])>0) //check if a single word exists in vocabulary
        {
            //extract the postlisting of the word i-th
            auto it = this->index.find(words[i]);
            posting_list = it->second;

            //check if the id_doc is already present in the postinglist

            for (int j = 0; j < posting_list.size(); j++) {
                if (posting_list[j][0].compare(id) == 0) {
                    //if I enter in the "if" I report it
                    check = true;
                    //take the score
                    score_sting = posting_list[j][1];
                    //convert the score in integer
                    string_int = stoi(score_sting);
                    //increment the score of 1
                    string_int++;
                    //reconvert the score in string;
                    score_sting = to_string(string_int);
                    //remove from posting_list old value
                    posting_list.erase(posting_list.begin()+j);
                    //delete all row of map
                    this->index.erase(it);
                    //update new value in map
                    id_score.push_back(id);
                    id_score.push_back(score_sting);
                    posting_list.push_back(id_score);
                    this->index.insert(pair<string, vector<vector<string>>>(words[i], posting_list));
                    posting_list.clear();
                    id_score.clear();
                    break;
                }
            }

        } else{
            //if I enter in the "else" I report it
            check = true;
            //update the vocabulary with new word and add new posting(id,score)
            id_score.push_back(id);
            id_score.push_back("1");
            posting_list.push_back(id_score);
            this->index.insert(pair<string, vector<vector<string>>>(words[i], posting_list));
            id_score.clear();
            posting_list.clear();
        }
        if (check == false) {
            //it means that the word[i] exists but the document has not yet been added to the postilisting of it
            id_score.push_back(id);
            id_score.push_back("1");
            this->index[words[i]].push_back(id_score);
            id_score.clear();
        }
    }
    return;
}

Preprocessing::Preprocessing(string path){
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
        removeDuplicate(id, words);



        c++;
        cout<<c<<endl;
        if (c == 200 ) {
            for (map<string, vector<vector<string>>>::iterator ii = this->index.begin(); ii != this->index.end(); ++ii) {
                cout << (*ii).first << ": ";
                vector<vector<string>> inVect = (*ii).second;
                for (int j = 0; j < inVect.size(); j++) {

                    cout << "(" << inVect[j][0] << "," << inVect[j][1] << "),";
                }
                cout << endl;
            }
            break;
        }

        
    }
        filein.close();

   


    //duplicate

    
    
}
