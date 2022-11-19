#include <string>
#include <vector>
#include <map>
#include <stxxl.h>
#include "utility/definition.h"
#include "utility/Print.h"

#ifndef BACKEND_INDEX_H
#define BACKEND_INDEX_H

using namespace std;

class Index {
private:
    lexicon_map *lexicon;
    documentIndex_map *documentIndex;

    lexicon_info_vector *lexiconInfo;
    docID_vector *docID;
    tf_vector *tf;

    int terms_counter = 0;

public:
    Index();
    Index(const Index&);

    void builtIndex(int,vector<string>);
    void addDocIndex(int, int);
    void addLexicon(int, string);
    void add_document_index(string, int);
    string docid(); //restituisce il docid del post corrente
    void next(); //sposta in sequenza l'iteratore al successivo
    void nextGEQ(string); //sposta l'iteratore al successivo con id del posting >=

};


#endif //BACKEND_INDEX_H
