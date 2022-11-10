#include <string>
#include <vector>
#include <map>

using namespace std;

#ifndef BACKEND_INDEX_H
#define BACKEND_INDEX_H
struct post{
    string id;
    int tf;
};

struct term_info{
    int df; //number of doc that mantein this term
    int cf; //total number of occurency
    int start_ind;
    int end_ind;
    vector<post> *posting_list;
};
class Index {
private:


public:
    map<string, term_info> lexicon;
    map<string,int> documentIndex;
    void addDocIndex(string,int);
    int addLexicon(string, string);
    void add_document_index(string,int);
    string docid(); //restituisce il docid del post corrente
    void next(); //sposta in sequenza l'iteratore al successivo
    void nextGEQ(string); //sposta l'iteratore al successivo con id del posting >=

};


#endif //BACKEND_INDEX_H
