// g++ -o main.exe main.cpp
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

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
    return 0;
}