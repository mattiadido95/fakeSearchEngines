#include <string>
#include <vector>
#include <map>
#include <stxxl.h>
#include "utility/utility.h"
#include "utility/definition.h"
#include "utility/Print.h"
#include "utility/FileManager.h"
#include <iostream>
#include <algorithm>


#ifndef BACKEND_INDEX_H
#define BACKEND_INDEX_H

using namespace std;

class Index {
private:
    utility util;
    Print print;

    FileManager* pDoc;
    FileManager* lexiconRead;
    FileManager* lexiconWrite;

    dictionaryVector* lexicon;
    documentIndex_map* documentIndex;
    lexicon_info_vector* lexiconInfo;
    docID_vector* docID;
    tf_vector* tf;
    int terms_counter = 0;

public:
    Index(string,string);
    Index(const Index&);

    void builtIndex();
    void addDocIndex(int, int);
    void addLexicon(int, string);
    void writeToFile();

    string docid(); //restituisce il docid del post corrente
    void next(); //sposta in sequenza l'iteratore al successivo
    void nextGEQ(string); //sposta l'iteratore al successivo con id del posting >=

};


#endif //BACKEND_INDEX_H
