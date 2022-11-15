#include <string>
#include <vector>
#include <map>
#include <stxxl.h>

#define DATA_NODE_BLOCK_SIZE (4096)
#define DATA_LEAF_BLOCK_SIZE (4096)
#ifndef BACKEND_INDEX_H
#define BACKEND_INDEX_H

using namespace std;

static const int MAX_KEY_LEN = 16;

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
        cout << "a" << a << endl;
        cout << "b" << b << endl;
        if(a.compare(b) > 0)
            return 1;
        return 0;
    }

    static std::string max_value() {
        return std::string(MAX_KEY_LEN, std::numeric_limits<unsigned char>::max());
    }
};

struct CompareGreaterInt {
    bool operator()(const int &a, const int &b) const { return a > b; }

    static int max_value() { return std::numeric_limits<int>::min(); }
};

class Index {
private:
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

    lexicon_map *lexicon;
    documentIndex_map *documentIndex;

    lexicon_info_vector *lexiconInfo;
    docID_vector *docID;
    tf_vector *tf;

    int terms_counter = 0;

public:

    void addDocIndex(int, int);

    void addLexicon(int, string);

    Index();

    void add_document_index(string, int);

    string docid(); //restituisce il docid del post corrente
    void next(); //sposta in sequenza l'iteratore al successivo
    void nextGEQ(string); //sposta l'iteratore al successivo con id del posting >=


};


#endif //BACKEND_INDEX_H
