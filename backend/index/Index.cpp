#include <algorithm>
#include "Index.h"
#include <string>
#include <iostream>
#include <stxxl.h>
#include <map>
#define DATA_NODE_BLOCK_SIZE (4096)
#define DATA_LEAF_BLOCK_SIZE (4096)
using namespace std;
//! [comparator]

//! [comparator]
//add id and length of the doc to the doc structure
Index::Index(){
    this->documentIndex = new documentIndex_map((documentIndex_map::node_block_type::raw_size)*3, (documentIndex_map::leaf_block_type::raw_size)*3);
    this->lexicon = new lexicon_map((lexicon_map::node_block_type::raw_size)*5, (lexicon_map::leaf_block_type::raw_size)*5);
}
void Index::addDocIndex(string docid, int len){
    // Constructor map(node_cache_size_in_bytes, leaf_cache_size_in_bytes)
    this->documentIndex->insert(pair<string,int>(docid,len));

}

//add token to the lexicon and create posting list
int Index::addLexicon(string docid, string token){
    term_info termInfo;
    post Post;
    vector<post> sad;
    if (lexicon->count(token)>0){ //if lexicon already contains that token
        auto it = lexicon->find(token);
        termInfo = *it->second;
        //update collection frequency for that token
        (*it->second).cf++;

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
        (*it->second).df++;
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

    map<string ,term_info> ciao;
    ciao.insert(pair<std::string,term_info>(token,termInfo));

    lexicon->insert(pair<std::string,term_info*>(token,(&termInfo)));
    return sizeof(termInfo)+sizeof((*termInfo.posting_list));
}