#include "utility.h"

void show_array(string arr[], int arraysize)
{
    for (int i = 0; i < arraysize; i++)
        cout << arr[i] << ", ";
}

void binary_search_stopwords(string arr[], int size)
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
