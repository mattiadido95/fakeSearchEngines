//
// Created by Matteo Giorgi on 16/11/22.
//

#ifndef BACKEND_DEFINITION_H
#define BACKEND_DEFINITION_H

#include <string>
#include <vector>
#include <stxxl.h>

using namespace std;

#define DATA_NODE_BLOCK_SIZE 1024
#define DATA_LEAF_BLOCK_SIZE 1024

static const int MAX_KEY_LEN = 16;
static const int MIN_KEY_LEN = 1;

struct post {
    string id;
    int tf;
};

struct term_info {
    int df; //number of doc that maintain this term
    int cf; //total number of occurrence
    int pos;

};

struct CompareGreaterString {
    bool operator()(const std::string &a, const std::string &b) const {
        return a > b;
    }

    static std::string max_value() {
        return std::string(MIN_KEY_LEN, '0');
    }

    static std::string min_value() {
        return std::string(MAX_KEY_LEN, 'z');
    }
};

struct CompareGreaterInt {
    bool operator()(const int &a, const int &b) const { return a > b; }

    static int min_value() { return std::numeric_limits<int>::max(); }
    static int max_value() { return std::numeric_limits<int>::min(); }
};

//  mappiamo per ogni docid il document length
typedef stxxl::map<int, int, CompareGreaterInt, DATA_NODE_BLOCK_SIZE, DATA_LEAF_BLOCK_SIZE> documentIndex_map;
/**
 * per ogni termine mappiamo un indice corrispondente alla posizione nel vettore di tipo lexicon_info_vector che conterrà le strutturo term info
 */
typedef stxxl::map<string, int, CompareGreaterString, DATA_NODE_BLOCK_SIZE, DATA_LEAF_BLOCK_SIZE> lexicon_map;
typedef stxxl::vector<term_info> lexicon_info_vector;
/**
 * il vettore di tipo lexicon_info_vector contiene pure la posizione della posting list del termine
 */
typedef stxxl::vector<vector<int>> docID_vector;
typedef stxxl::vector<vector<int>> tf_vector;

#endif //BACKEND_DEFINITION_H
