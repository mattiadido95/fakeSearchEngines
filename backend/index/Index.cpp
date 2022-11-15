#include <algorithm>
#include "Index.h"
#include <string>
#include <iostream>
#include <stxxl.h>
#include <map>

#define DATA_NODE_BLOCK_SIZE (4096)
#define DATA_LEAF_BLOCK_SIZE (4096)
using namespace std;


//add id and length of the doc to the doc structure
Index::Index() {
    this->documentIndex = new documentIndex_map((documentIndex_map::node_block_type::raw_size) * 3,
                                                (documentIndex_map::leaf_block_type::raw_size) * 3);
    this->lexicon = new lexicon_map((lexicon_map::node_block_type::raw_size) * 5,
                                    (lexicon_map::leaf_block_type::raw_size) * 5);
    this->lexiconInfo = new lexicon_info_vector;
    this->docID = new docID_vector;
    this->tf = new tf_vector;
}

void Index::addDocIndex(int docid, int len) {
    // Constructor map(node_cache_size_in_bytes, leaf_cache_size_in_bytes)
    this->documentIndex->insert(pair<int, int>(docid, len));
}

//add token to the lexicon and create posting list
void Index::addLexicon(int docid, string token) {
    term_info termInfo;
    post Post;
    vector<post> sad;

    cout << "token -> " << token << endl;
    
    if (lexicon->find(token) != lexicon->end()) {
        // term is already into lexicon
        return;
    } else {
        // term not in lexicon
        // -> add into lexicon map new term with the positional index of the vector lexiconInfo
        // -> create term info struct with cf df and index to tf_vector and docID_vector
        // -> add the new doc id and the new tf into tf_vector and docID_vector

        vector<int> docid_new;
        docid_new.push_back(docid);
        docID->push_back(docid_new);

        vector<int> tf_new;
        tf_new.push_back(1);
        tf->push_back(tf_new);

        termInfo.cf = 1;
        termInfo.df = 1;
        termInfo.pos = this->terms_counter;

        this->lexiconInfo->push_back(termInfo);

        this->lexicon->insert(pair<string, int>(token, this->terms_counter));

        cout << this->terms_counter<<endl;

        this->terms_counter++;

    }

    return;
}