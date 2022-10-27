// g++ -o main.out main.cpp && ./main.out
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "preprocessing.h"

using namespace std;

void show_array(string arr[], int arraysize)
{
    for (int i = 0; i < arraysize; i++)
        cout << arr[i] << ", ";
}

void binarySearch(string arr[], int size)
{
    cout << "\nThe array is : \n";
    show_array(arr, size);

    // Sort string array a for binary search as prerequisite
    sort(arr, arr + size);

    // Finding for "Geeks"
    cout << "\n\nSearching Result for \"Geeks\"";
    if (binary_search(arr, arr + size, "Geeks"))
        cout << "\nString Founded in array\n";
    else
        cout << "\nString not Founded in array\n";

    // Finding for string str
    string str = "Best";
    cout << "\nSearching Result for \"Best\"";
    if (binary_search(arr, arr + size, str))
        cout << "\nString Found in array";
    else
        cout << "\nString not Found in array";
}

string *vectorToArray(vector<string> tokenList)
{
    int arraySize = tokenList.size();
    string *arrayString = new string[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        arrayString[i] = tokenList[i];
    }

    return arrayString;
}

int main()
{
     ifstream filein("../data/collection.tsv");
     int c;
     c = 0;

     for (string line; getline(filein, line);)
     {
         cout << line << endl;
         c++;
         if (c == 1024)
         {
             break;
         }
     }

     filein.close();

    // preprocessing
    Preprocessing preprocess;
    // vector<string> stopwords = preprocess.stopwords();

    string stopwords[] = {"Geeks", "For", "GeeksForGeek"};
    int size = sizeof(stopwords) / sizeof(stopwords[0]);
    sort(stopwords, stopwords + size);
    string str = "For";

    if (binary_search(stopwords, stopwords + size, str))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}