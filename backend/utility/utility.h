#ifndef BACKEND_UTILITY_H
#define BACKEND_UTILITY_H


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class utility {

public:
    void show_array(string arr[], int arraysize);

    string *vector_to_array(vector<string> token_list);

    int binary_search(vector<string> stopwords, string token, int size);
};

#endif //BACKEND_UTILITY_H
