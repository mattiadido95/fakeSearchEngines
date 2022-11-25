#include "Index.h"

using namespace std;

//add id and length of the doc to the doc structure
Index::Index(string collectionPath, string lexiconPath) {
    this->pDoc = new FileManager(collectionPath,"read");
    this->lexiconWrite = new FileManager(lexiconPath,"write");

    this->lexicon = new dictionaryVector;
    this->lexiconInfo = new lexicon_info_vector;
    this->docID = new docID_vector;
    this->tf = new tf_vector;
}

Index::Index(const Index& c){
    cout << "Copy constructor" << endl;
}

//takes id and tokenized words of the doc
void Index::builtIndex() {
    string doc = pDoc->readLine();
    int docid;
    vector<string> words;

    while (doc != "") {
        words = util.split(doc,string(" "));

        //get docid
        docid = stoi(words[0]);
        words.erase(words.begin());

        addDocIndex(docid, words.size());
        for (int i = 0; i < words.size(); i++)
            addLexicon(docid, words[i]);

        doc = pDoc->readLine();
    }
}


void Index::addDocIndex(int docid, int len) {
    // Constructor map(node_cache_size_in_bytes, leaf_cache_size_in_bytes)
    this->documentIndex->insert(pair<int, int>(docid, len));
}

//add token to the lexicon and create posting list
void Index::addLexicon(int docid, string token) {
    term_info termInfo;
    post Post;

    int pos = util.findPosition(token,*this->lexicon);
    if (pos != -1) {
        //get the position of the posting list of the token
       // cout << "elemento gia presente " << token << endl;
        //check if the doc have already this token
        //vector<int> doclist = (*docID)[pos];
        vector<int>::iterator it;
        it = find ((*docID)[pos].begin(), (*docID)[pos].end(), docid);
        if (it != (*docID)[pos].end()){
            int index = it - (*docID)[pos].begin();
            (*tf)[pos][index]++;
            (*lexiconInfo)[pos].df++;
        }else{
            (*docID)[pos].push_back(docid);
            (*tf)[pos].push_back(1);
            (*lexiconInfo)[pos].cf++;
            (*lexiconInfo)[pos].df++;
        }
    } else {
//         term not in lexicon
//         -> add into lexicon map new term with the positional index of the vector lexiconInfo
//         -> create term info struct with cf df and index to tf_vector and docID_vector
//         -> add the new doc id and the new tf into tf_vector and docID_vector
     //   cout << "elemento non presente " << token << endl;

        vector<int> docid_new;
        docid_new.push_back(docid);
        docID->push_back(docid_new);

        vector<int> tf_new;
        tf_new.push_back(1);
        tf->push_back(tf_new);

        termInfo.cf = 1;
        termInfo.df = 1;
        termInfo.pos = this->terms_counter;


        this->lexiconInfo->push_back(termInfo);
        this->lexicon->push_back(token);
        this->terms_counter++;
        cout << this->terms_counter << endl;
    }

    return;
}

//write lexicon to filesystem
void Index::writeToFile(){
    for(int i = 0; i < lexicon->size(); i++){
        string dict = (*lexicon)[i] + " " + to_string(i);
        lexiconWrite->writeLine(dict);
    }
}