#include<fstream>
#include<string>
#include<vector>

using namespace std;

class FileManager{
    private:
        string path;
        ifstream file;
    public:
        FileManager(string path);
        vector<string> readFile();
        string readLine();
        ~FileManager();
};