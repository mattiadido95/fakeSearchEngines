#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void show_array(string arr[], int arraysize);

string *vector_to_array(vector<string> token_list);

void binary_search_stopwords(string stopwords[], int size, string word);

int binary_search(string arr[], string x, int n);

void my_search(vector<string> stopwords, vector<string> tokens);