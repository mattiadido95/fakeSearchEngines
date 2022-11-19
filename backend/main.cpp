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

using namespace std;

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

    Preprocessing p("../../data/collection.tsv");
    Index i("../../data/preprocecedcollection.txt");
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

}