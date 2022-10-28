#include "utility.h"

void show_array(string arr[], int arraysize)
{
    for (int i = 0; i < arraysize; i++)
        cout << arr[i] << ", ";

    cout << endl;
}

string *vector_to_array(vector<string> tokenList)
{
    int arraySize = tokenList.size();
    string *arrayString = new string[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        arrayString[i] = tokenList[i];
    }
    for (int s = 0; s < arraySize; s++)
    {
        cout << arrayString[s] << "," << arrayString[s].length() << endl;
    }

    return arrayString;
}

int binary_search(string arr[], string x, int n)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        int res = -1000; // some random value assigned because if res is already 0 then
                         // it will always return 0
        if (x.compare(arr[m]) == 0)
        {
            cout << "check " << x << " = " << arr[m] << endl;
            res = 0;
        }

        // Check if x is present at mid
        if (res == 0)
        {
            cout << "FOUND" << endl;
            return m;
        }

        // If x greater, ignore left half
        if (x.compare(arr[m]) > 0)
        {
            cout << "check " << x << "=" << arr[m] << endl;
            l = m + 1;
        }

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return -1;
}

void binary_search_stopwords(string stopwords[], int size, string word)
{
    // cout << "\nThe array is : \n";
    // show_array(arr, size);

    // // Sort string array a for binary search as prerequisite
    // sort(arr, arr + size);

    // // Finding for "Geeks"
    // cout << "\n\nSearching Result for \"Geeks\"";
    // if (binary_search(arr, arr + size, "Geeks"))
    //     cout << "\nString Founded in array\n";
    // else
    //     cout << "\nString not Founded in array\n";

    // // Finding for string str
    // string str = "Best";
    // cout << "\nSearching Result for \"Best\"";

    if (binary_search(stopwords, stopwords + size, word))
        cout << "YES -> stopword find" << endl;
    else
        cout << "NO -> stopword not found" << endl;

    cout << endl;
}

void my_search(vector<string> stopwords, vector<string> tokens)
{
    vector<int> index;

    string *tokens_array = vector_to_array(tokens);
    string *stopwords_array = vector_to_array(stopwords);

    for (int s = 0; s < stopwords.size(); s++)
    {
        // cout << stopwords[s] << " -> " << endl;
        for (int t = 0; t < tokens.size(); t++)
        {
            // cout << tokens[t] << ", ";
            if (stopwords_array[s].compare(tokens_array[t]) == 0)
            {
                cout << "- FOUND -> " << stopwords[s] << " - " << tokens[t] << endl;
                // index.push_back(t);
            }
            // else
            // {
            //     cout << "- NOT FOUND -> " << stopwords[s] << " - " << tokens[t] << endl;
            // }
        }
        cout << endl;
    }
    /* cout << "-----------" << endl;
    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << endl;
    }
    cout << "-----------" << endl; */
}