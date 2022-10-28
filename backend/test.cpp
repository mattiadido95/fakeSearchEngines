// C++ program to store the string as
// the map value
#include <iostream>
#include <map>
using namespace std;

// Driver code
int main()
{
	// Get the Strings
	string s = "abc";
	string s1 = "bca";
	string s2 = "cba";

	// Declare map with both value
	// and key having string data_type
	map<string, int> m;

	// Insert the string in the map
    m.insert(pair<string, int>(s1, 0));

	// Print the elements stored
	// in the map
	for (auto itr = m.begin();
		itr != m.end(); ++itr) {
		cout << itr->first << '\t'
			<< itr->second << '\n';
	}

	return 0;
}
