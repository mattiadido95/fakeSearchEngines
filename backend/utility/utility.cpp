#include "utility.h"

void utility::show_array(string arr[], int arraysize) {
    for (int i = 0; i < arraysize; i++)
        cout << arr[i] << ", ";

    cout << endl;
}

string *utility::vector_to_array(vector<string> tokenList) {
//    not work very well
    int arraySize = tokenList.size();
    string *arrayString = new string[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayString[i] = tokenList[i];
    }
    for (int s = 0; s < arraySize; s++) {
        cout << arrayString[s] << "," << arrayString[s].length() << endl;
    }

    return arrayString;
}

int utility::binary_search(vector<string> stopwords, string token, int size) {
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = -1000; // some random value assigned because if res is already 0 then
//        it will always return 0
        if (token.compare(stopwords[m]) == 0) {
            res = 0;
        }
//        Check if x is present at mid
        if (res == 0) {
            return m;
        }
//        If x greater, ignore left half
        if (token.compare(stopwords[m]) > 0) {
            l = m + 1;
        }
//        If x is smaller, ignore right half
        else { r = m - 1; }
    }
    return -1;
}

vector<string> utility::split(string doc,string delimiter){
    size_t pos = 0;
    vector<string> result;
    while ((pos = doc.find(delimiter)) != std::string::npos) {
        result.push_back(doc.substr(0, pos));
        doc.erase(0, pos + delimiter.length());
    }
    return result;
}


