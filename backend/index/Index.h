#include <string>
#include <vector>
#include <map>
#include <stxxl>

using namespace std;

#ifndef BACKEND_INDEX_H
#define BACKEND_INDEX_H
struct post {
    string id;
    int tf;
};

struct term_info {
    int df; //number of doc that maintain this term
    int cf; //total number of occurrence
    int start_ind;
    int end_ind;
    vector<int> prova;
    vector<post> *posting_list;
};

class Index {

private:
    map<string, term_info> lexicon;
    map<string, int> documentIndex;
    stxxl::vector<int> prova;
public:
    void addDocIndex(string, int);

    int addLexicon(string, string);

    void add_document_index(string, int);

    string docid(); //restituisce il docid del post corrente
    void next(); //sposta in sequenza l'iteratore al successivo
    void nextGEQ(string); //sposta l'iteratore al successivo con id del posting >=

    map<string, term_info> getLexicon() { return lexicon; }

    map<string, int> getDocumentIndex() { return documentIndex; }

};


#endif //BACKEND_INDEX_H
