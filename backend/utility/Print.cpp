//
// Created by Matteo Giorgi on 16/11/22.
//

#include "Print.h"

void Print::vectorInt(const stxxl::vector<int> v){
    cout << "------Vector------" << endl;
    for(int i = 0; i < v.size(); i++)
        cout << i << "-->" << v[i] << endl;
}
void Print::vectorTermInfo(const stxxl::vector<term_info> v){
    cout << "------Vector------" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << i << endl;
        cout << "\t" << "cf" << "-->" << v[i].cf << endl;
        cout << "\t" << "df" << "-->" << v[i].df << endl;
        cout << "\t" << "pos" << "-->" << v[i].pos << endl;
    }
}
void Print::mapString(lexicon_map* m){
    cout << "------Lexicon------" << endl;
    for (lexicon_map::iterator iter = m->begin(); iter != m->end(); ++iter){
        std::cout << iter->first << " => " << iter->second << std::endl;
    }
}
void Print::mapInt(documentIndex_map* m){
    cout << "------Document------" << endl;
    for (documentIndex_map::iterator iter = m->begin(); iter != m->end(); ++iter){
        std::cout << iter->first << " => " << iter->second << std::endl;
    }
}

