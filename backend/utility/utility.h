#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void show_array(string arr[], int arraysize);

string *vector_to_array(vector<string> token_list);

int binary_search(vector<string> stopwords, string token, int size);

vector<int> my_search(vector<string> stopwords, vector<string> tokens);