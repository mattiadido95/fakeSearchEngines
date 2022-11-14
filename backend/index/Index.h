#include <string>
#include <vector>
#include <map>
#include <stxxl.h>
#define DATA_NODE_BLOCK_SIZE (4096)
#define DATA_LEAF_BLOCK_SIZE (4096)
using namespace std;

#ifndef BACKEND_INDEX_H
#define BACKEND_INDEX_H
static const int MAX_KEY_LEN = 16;
struct post {
    string id;
    int tf;
};

struct term_info {
    int df; //number of doc that maintain this term
    int cf; //total number of occurrence
    int start_ind;
    int end_ind;
    vector<post> *posting_list;
};
struct CompareGreater
{
    bool operator () (const std::string& a, const std::string& b) const {
        return a > b;
    }
    static std::string max_value() {
        return std::string(MAX_KEY_LEN, std::numeric_limits<unsigned char>::max());
    }
};

class Index {
private:
    typedef stxxl::map<string, term_info,CompareGreater,DATA_NODE_BLOCK_SIZE,DATA_LEAF_BLOCK_SIZE> lexicon_map;
    typedef stxxl::map<string, int, CompareGreater, DATA_NODE_BLOCK_SIZE,DATA_LEAF_BLOCK_SIZE> documentIndex_map;
    lexicon_map * lexicon;
    documentIndex_map * documentIndex;
    typedef stxxl::vector<vector<int>> id_post;
    typedef stxxl::vector<vector<int>> tf_post;


public:

    void addDocIndex(string, int);

    int addLexicon(string, string);
    Index();

    void add_document_index(string, int);

    string docid(); //restituisce il docid del post corrente
    void next(); //sposta in sequenza l'iteratore al successivo
    void nextGEQ(string); //sposta l'iteratore al successivo con id del posting >=


};


#endif //BACKEND_INDEX_H
