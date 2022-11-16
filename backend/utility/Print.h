//
// Created by Matteo Giorgi on 16/11/22.
//

#ifndef BACKEND_PRINT_H
#define BACKEND_PRINT_H

#include "utility/definition.h"
#include <stxxl/map>
#include <stxxl/vector>


using namespace std;


class Print {

public:
    void vectorInt(const stxxl::vector<int>);
    void vectorTermInfo(const stxxl::vector<term_info>);
    void mapString(lexicon_map*);
    void mapInt(documentIndex_map*);
};

#endif //BACKEND_PRINT_H
