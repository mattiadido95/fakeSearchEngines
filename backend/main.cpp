////g++ -o main.out -I ./utilityold *.cpp utilityold/*.cpp
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <regex>
//#include <algorithm> //serve per lower o upper
//#include "preprocessing.h"
//#include "utility/FileManager.h"
//#include "utility/availableMemory.cpp"
//#include "index/Index.h"
////#include "psapi.h"
////#include "windows.h"
//#include <chrono>
//
//using namespace std;
//
//int main() {
//    // start preprocessing
////    unsigned long long Memory = getTotalSystemMemory();
////    cout<<Memory<<endl;
//
//    auto start = chrono::steady_clock::now();
//    Index *index = new Index;
//
//    Preprocessing p("../../data/collection.tsv", index);
////    Memory = getTotalSystemMemory();
////    cout<<"Finisch memory:  "<<Memory<<endl;
//    auto end = chrono::steady_clock::now();
//    cout << "Elapsed time in seconds: "
//         << chrono::duration_cast<chrono::seconds>(end - start).count()
//         << " sec";
//    return 0;
//}


// CANCELLARE da qui in giu  ---------------------
#include <stxxl/map>
#include <iostream>
#define DATA_NODE_BLOCK_SIZE (4096)
#define DATA_LEAF_BLOCK_SIZE (4096)
//! [comparator]
struct CompareGreater
{
    bool operator () (const int& a, const int& b) const
    { return a > b; }
    static int max_value()
    { return std::numeric_limits<int>::min(); }
};

struct CompareGreaterString {
    bool operator()(const std::string &a, const std::string &b) const {
        return a > b;
    }

    static std::string max_value() {
        return std::string(16, 'Z');
    }
};

//! [comparator]
int main()
{

    std::cout << std::numeric_limits<unsigned char>::max() << std::endl;
    // template parameter <KeyType, DataType, CompareType, RawNodeSize, RawLeafSize, PDAllocStrategy (optional)>
    typedef stxxl::map<std::string , char, CompareGreaterString, DATA_NODE_BLOCK_SIZE, DATA_LEAF_BLOCK_SIZE> map_type;
    // Constructor map(node_cache_size_in_bytes, leaf_cache_size_in_bytes)
    map_type* p = new map_type((map_type::node_block_type::raw_size) * 3,
                               (map_type::leaf_block_type::raw_size) * 3);
    p->insert(std::pair<std::string , char>("ciao", 'a'));
    map_type my_map((map_type::node_block_type::raw_size)*3, (map_type::leaf_block_type::raw_size)*3);
//    my_map.insert(std::pair<int, char>(1, 'a'));
//    my_map.insert(std::pair<int, char>(2, 'b'));
//    my_map.insert(std::pair<int, char>(3, 'c'));
//    my_map.insert(std::pair<int, char>(4, 'd'));
//    my_map.erase(3);
    map_type::iterator iter;
    std::cout << "my_map contains:\n";
    for (iter = p->begin(); iter != p->end(); ++iter)
    {
        std::cout << iter->first << " => " << iter->second << std::endl;
    }
    map_type::iterator iter_low, iter_up;
//    iter_low = my_map.lower_bound(1); // iter_low points to (1,a) in this case
//    iter_up = my_map.upper_bound(3); // iter_up points to (2,b) in this case
    std::cout << "lower bound " << iter_low->second << ", upper bound " << iter_up->second << std::endl;
    return 0;
}