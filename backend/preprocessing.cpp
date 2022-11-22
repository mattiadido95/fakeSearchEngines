#include "preprocessing.h"
#include <string>
#include <vector>
#include <regex>
#include <algorithm> //serve per lower o upper

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

/*
 * lessico : termine, df, cf, vector<int> posizione blocchi
 * docinfo : dociid, len_doc
 * posting list : doc_id, tf
 *
 * hash term -> vector<posting> (memory mapping)
 */

vector<string> Preprocessing::removeStopword(vector<string> words) {
    //  get stopwords list
    //cout << "- start import stopword list ..." << endl;
    vector<string> stopwords = stopwordsFile->readFile();
    //cout << "   -> number of stopword imported " << stopwords.size() << endl;

    //      create for loop to remove stopwords from tokens list
    //cout << "- start find stopword into tokens ..." << endl;
    vector<int> index_list; // list of index to remove from tokens list that match with stopwords
    std::sort(words.begin(), words.end()); // sort word array to implement binary search
    for (vector<string>::iterator s = stopwords.begin(); s != stopwords.end(); s++) {
        // cout << "   -> find stopword: " << *s << ": ";

        int res = util.binary_search(words, *s, words.size());
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


Preprocessing::Preprocessing(string path) {
    docsFile = new FileManager(path,false);
    stopwordsFile = new FileManager("../../data/stop_words_english.txt",false);
    outputFile = new FileManager("../../data/preprocessed_collection.txt",true);
    vector<string> words;
    ifstream filein(path);
    int c = 0;

    string doc = docsFile->readLine();

    while(doc != ""){
        c++;
        words = tokenization(doc);
        //store id and remove it form doc
        int id = stoi(words[0]);
        words.erase(words.begin());
        //stopword
        words = removeStopword(words);
        //stemming
        words = porterStemming(words);

        //write into result file
        outputFile->writeLine(id,words);

        //get next doc
        doc = docsFile->readLine();
        if(c%1000==0)
            cout<<c<<endl;
        if(c == 10000)
            break;
    }
}


