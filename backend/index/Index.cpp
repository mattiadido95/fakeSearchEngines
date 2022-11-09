#include <algorithm>
#include "Index.h"
#include <string>
#include <iostream>
using namespace std;

void Index::addDocIndex(string docid, int len){
    documentIndex.insert(pair<string,int>(docid,len));
}

void Index::addLexicon(string docid, string token){
    term_info termInfo;
    post Post;
    vector<post> sad;

    if (lexicon.count(token)>0){ //check if a single word exists in vocabulary
        auto it = this->lexicon.find(token);
        termInfo = it->second;
        it->second.cf++;



        for(int i = 0; i< static_cast<vector<post>>(*termInfo.posting_list).size(); i++){
            if ((*termInfo.posting_list)[i].id == docid){

                 (*termInfo.posting_list)[i].tf ++;

                return;
            }
        }
        Post.id = docid;
        Post.tf = 1;
        it->second.df++;
        (*termInfo.posting_list).push_back(Post);
        return;

}
    termInfo.cf = 1;
    termInfo.df = 1;
    termInfo.start_ind = 0;
    termInfo.end_ind = 0;
    Post.id = docid;
    Post.tf = 1;
    vector<post>* pl = new vector<post>();
    (*pl).push_back(Post);
    termInfo.posting_list= pl;
    lexicon.insert(pair<string,term_info>(token,termInfo));
    return;
}