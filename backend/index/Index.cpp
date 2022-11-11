#include <algorithm>
#include "Index.h"
#include <string>
#include <iostream>
using namespace std;

//add id and length of the doc to the doc structure
void Index::addDocIndex(string docid, int len){
    documentIndex.insert(pair<string,int>(docid,len));
}

//add token to the lexicon and create posting list
int Index::addLexicon(string docid, string token){
    term_info termInfo;
    post Post;
    std::vector<post> sad;

    if (lexicon.count(token)>0){ //if lexicon already contains that token
        auto it = this->lexicon.find(token);
        termInfo = it->second;
        //update collection frequency for that token
        it->second.cf++;

        //search for the post related to that doc
        for(int i = 0; i< (*termInfo.posting_list).size(); i++){
            if ((*termInfo.posting_list)[i].id == docid){
                 (*termInfo.posting_list)[i].tf ++;
                return 0;
            }
        }

        //doc id not present in the posting list for that token
        Post.id = docid;
        Post.tf = 1;

        //increment df each time I increment the posting list
        it->second.df++;
        (*termInfo.posting_list).push_back(Post);
        return sizeof(Post);

    }
    //document not contain the token
    termInfo.cf = 1;
    termInfo.df = 1;
    termInfo.start_ind = 0;
    termInfo.end_ind = 0;

    Post.id = docid;
    Post.tf = 1;

    //crete vector of posting list
    termInfo.posting_list = new vector<post>();
    (*termInfo.posting_list).push_back(Post);

    lexicon.insert(pair<string,term_info>(token,termInfo));
    return sizeof(termInfo)+sizeof((*termInfo.posting_list));
}