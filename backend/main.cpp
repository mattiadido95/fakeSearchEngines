//g++ -o main.out -I ./utilityold *.cpp utilityold/*.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <algorithm> //serve per lower o upper
#include "preprocessing.h"
#include "utility/availableMemory.cpp"
#include "index/Index.h"
//#include "psapi.h"
//#include "windows.h"
#include <chrono>



#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

string s;

int main() {
    // start preprocessing
//    unsigned long long Memory = getTotalSystemMemory();
//    cout<<Memory<<endl;

//    auto start = chrono::steady_clock::now();
//

//    Memory = getTotalSystemMemory();
//    cout<<"Finisch memory:  "<<Memory<<endl;
//    auto end = chrono::steady_clock::now();
//    cout << "Elapsed time in seconds: "
//         << chrono::duration_cast<chrono::seconds>(end - start).count()
//         << " sec";

//    Preprocessing p("../../data/collection.tsv");
    Index i("../../data/preprocessed_collection.txt","../../data/lexicon.txt");
    i.builtIndex();
    return 0;


//    typedef stxxl::vector<term_info> vectort;
//    typedef stxxl::map<string,int,CompareGreaterString,DATA_NODE_BLOCK_SIZE,DATA_LEAF_BLOCK_SIZE> maps;
//    typedef stxxl::vector<std::vector<int>> v;
//    v* vv;
//    maps* m;
//    vectort* p;
//    p = new vectort;
//    vv = new v;
//    m = new maps((maps::node_block_type::raw_size)*5,
//                (maps::leaf_block_type::raw_size)*5);
//    for (int i = 0; i < 1024 * 1024 * 1024; i++)
//    {
////        term_info t;
////        t.df = i;
////        t.cf = i;
////        t.pos = i;
//        cout << i << endl;
//
//        //vector of terminfo
////        p->push_back(t);
//
//        //map of int int
//        m->insert(pair<string,int>(to_string(i),i+1));
//
//        // vector of vector
////        std::vector<int> a;
////        a.push_back(i);
////        vv->push_back(a);
//    }
//
//    return 0;
//
////! [hash]
//    struct HashFunctor
//    {
//        size_t operator () (string sss) const
//        {
//            cout << s << endl;
//            string res;
//            for(int i=0; i<s.size();i++){
//                res += to_string((int)s[i]);
//            }
//            cout << res << endl;
//            // a simple integer hash function
//            return (size_t)(stoi(res) * 2654435761u);
//        }
//    };
////! [hash]
////! [comparator]
//    struct CompareLess
//    {
//        bool operator () (const string& a, const string& b) const
//        { return a < b; }
//        static string min_value() { return std::string(1, std::numeric_limits<char>::min()); }
//        static string max_value() { return std::string(16, std::numeric_limits<char>::max()); }
//    };
////! [comparator]
//
////! [construction]
//#define SUB_BLOCK_SIZE 8192
//#define SUB_BLOCKS_PER_BLOCK 256
//
//        // template parameter <KeyType, MappedType, HashType, CompareType, SubBlockSize, SubBlocksPerBlock>
//        typedef stxxl::unordered_map<
//                string, int, HashFunctor, CompareLess, SUB_BLOCK_SIZE, SUB_BLOCKS_PER_BLOCK
//        > unordered_map_type;
//        // constructor: use defaults for all parameters
//        unordered_map_type my_map;
////! [construction]
//
//        // insert some items and delete one
//        s = "ciao";
//        my_map.insert(std::pair<string,int>(s, 1));
//    s = "ciaq";
//        my_map.insert(std::make_pair(s, 2));
//    s = "cia1";
//        my_map.insert(std::make_pair("cia1", 3));
//    s = "ciad";
//        my_map.insert(std::make_pair("ciad", 4));
////        my_map.erase(3);
////        // iterate over all items in the unordered_map
//        unordered_map_type::iterator iter;
//        std::cout << "my_map contains:\n";
//        for (iter = my_map.begin(); iter != my_map.end(); ++iter)
//        {
//            std::cout << iter->first << " => " << iter->second << std::endl;
//        }
////        // direct operator[] access to items
////        std::cout << "my_map[2] = " << my_map[2] << std::endl;
////        // efficient bulk-insert into hash map by sorting by hash keys
////        std::vector<unordered_map_type::value_type> value_array;
////        for (int i = 0; i < 128; ++i)
////            value_array.push_back(std::make_pair(i, (char)i));
////        my_map.insert(value_array.begin(), value_array.end(), 8 * 1024 * 1024);
////        // check results of insertion
////        std::cout << "my_map[42] = " << my_map[42] << std::endl;
////        std::cout << "my_map.size() = " << my_map.size() << std::endl;
//        return 0;

//    int fd = open("../../data/lexicon.txt", O_RDWR, S_IRUSR | S_IWUSR);
//    struct stat sb;
//
//    if(fstat(fd,&sb) == -1){
//        perror("couldn't get file size\n");
//    }
//    printf("file size is %ld\n",sb.st_size);
//    char* file_mem = (char*) mmap(NULL,sb.st_size,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
//    bool check = false;
//    bool found = false;
//    string term = "";
//    string pos = "";
//    for(int i = 0; i < sb.st_size; i++){
//        if(file_mem[i] == ' ') {
//            check = true;
//            if(term.compare("ccc") == 0){
//                found = true;
//            }
//            continue;
//        }
//        if(!check){ // false
//            term += file_mem[i];
//        }else{ // true
//            if(file_mem[i] != '\n') {
//                pos += file_mem[i];
//            }else{
//                if(found){
//                    cout << pos << endl;
//                    break;
//                }
//                check = false;
//                term = "";
//                pos = "";
//            }
//        }
//    }
//    munmap(file_mem,sb.st_size);
//    close(fd);
//    if(!found) {
//        cout << "aggiungi" << endl;
//        ofstream fd;
//        fd.open("../../data/lexicon.txt",ios_base::app);
//        fd << "caio " << to_string(1) << endl;
//    }

}