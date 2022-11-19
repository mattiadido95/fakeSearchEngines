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

vector<string> Preprocessing::tokenization(string doc) {
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

/*
 * lessico : termine, df, cf, vector<int> posizione blocchi
 * docinfo : dociid, len_doc
 * posting list : doc_id, tf
 *
 * hash term -> vector<posting> (memory mapping)
 */

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

//takes id and tokenized words of the doc
int Preprocessing::build_index(int docid, vector<string> words) {
    int weight = 0;
    this->index->addDocIndex(docid, words.size());
    for (int i = 0; i < words.size(); i++) {
        this->index->addLexicon(docid,words[i]);
    }
    return weight;
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

Preprocessing::Preprocessing(string path, Index *index) {
    this->index = index;
    vector<string> words;
    vector<string> words2;
    vector<string> support;
    vector<string> wordsdocs;
    ifstream filein(path);
    int c = 0, weight = 0;


    for (string doc; getline(filein, doc);) {
        words = tokenization(doc);

        //store id and remove it form doc
        int id = stoi(words[0]);
        words.erase(words.begin());
        //stopword
        words = removeWordstop(words);
        //stemming
        words = porterStemming(words);
        //index
        //1. add info of the document
        weight += build_index(id, words);

        //cout<< "Tot MB:  "<< weight/1000<<endl;

        c++;
        if ((c % 1000)==0) {

            break;
            if(c == 20000)
                break;

//            ifstream file_term, file_ii;
//            file_term.open("../../data/index/vocabulary.txt");
//            file_ii.open("../../data/index/invertindex.txt");
//            regex re("\\,");
//            vector<post> extract_posts;
//            post extract_post;
//            if (file_term) {
//                string word;
//                string invrtIndex;
//                ofstream term("../../data/index/vocabulary1.txt");
//                ofstream invertindex("../../data/index/invertindex1.txt");
//                int line_doc = 0; //mi segno in che liena del doc mi trovo
//                while (getline(file_term, word) && (getline(file_ii, invrtIndex))) {
//                    //rimove , of the dectionary
//                    sregex_token_iterator it(word.begin(), word.end(), re, -1);
//                    sregex_token_iterator reg_end;
//                    //extract by line the values
//                    string token;
//                    term_info termInfo;
//                    token = it->str();
//                    ++it;
//                    termInfo.cf = stoi(it->str());
//                    ++it;
//                    termInfo.df = stoi(it->str());
//
//                    for (auto ii = this->index->getLexicon().begin(); ii != this->index->getLexicon().end(); ++ii) {
//                        if (token.compare(ii->first) ==
//                            0) //check if the line of vocabulary and token that I have, they are equal
//                        {
//                            // cout<< "term save: "<<token<<" cf: "<< termInfo.cf<< " df: "<< termInfo.df<<endl;
//                            // cout<< "term new: "<< ii->first << "," << ii->second.cf << "," << ii->second.df << endl;
//                            termInfo.cf += ii->second.cf;
//                            termInfo.df += ii->second.df;
//                            //  cout<< "fusion: "<<token <<" cf: "<< termInfo.cf<< " df: "<< termInfo.df<<endl;
//                            term << token << "," << termInfo.cf << "," << termInfo.df
//                                 << endl; // apdate the value ov vocabulary
//                            //update the vector of invetedindex
//
//                            sregex_token_iterator ll(invrtIndex.begin(), invrtIndex.end(), re, -1);
//                            sregex_token_iterator reg_end;
//                            for (; ll != reg_end; ++ll) {
//                                extract_post.id = ll->str();
//                                ++ll;
//                                extract_post.tf = stoi(ll->str());
//                                extract_posts.push_back(extract_post);
//                            }
//                            extract_posts.insert(extract_posts.end(), (*ii->second.posting_list).begin(),
//                                                 (*ii->second.posting_list).end());
//                            for (int i = 0; i < extract_posts.size(); i++) {
//                                invertindex << extract_posts[i].id << "," << extract_posts[i].tf;
//                                if (i != extract_posts.size() - 1)
//                                    invertindex << ",";
//                            }
//                            extract_posts.clear();
//                            invertindex << endl;
//                        }
//                    }
//                }
//                term.close();
//                invertindex.close();
//                file_term.close();
//                file_ii.close();
//                remove("../../data/index/vocabulary.txt");
//                remove("../../data/index/invertindex.txt");
//                rename("../../data/index/vocabulary1.txt", "../../data/index/vocabulary.txt");
//                rename("../../data/index/invertindex1.txt", "../../data/index/invertindex.txt");
//            } else {
//                ofstream term("../../data/index/vocabulary.txt");
//                ofstream invertindex("../../data/index/invertindex.txt");
//                for (auto ii = this->index->getLexicon().begin(); ii != this->index->getLexicon().end(); ++ii) {
//                    term << ii->first << "," << ii->second.cf << "," << ii->second.df << endl;//term,cf,df
//                    //    cout << ii->first << "," << ii->second.cf << "," << ii->second.df << endl;
//                    for (int i = 0; i < (*ii->second.posting_list).size(); i++) {
//                        invertindex << (*ii->second.posting_list)[i].id << "," << (*ii->second.posting_list)[i].tf;
//                        if (i != (*ii->second.posting_list).size() - 1)
//                            invertindex << ",";
//                    }
//                    invertindex << endl;
//                }
//                term.close();
//                invertindex.close();
//            }
//            //cout<<"peso effettivo:"  <<weight<<endl;
//            cout << "indice caricato: " << c * 100 / 8841822 << "%" << endl;
        }


    }
    filein.close();




    //duplicate



}


