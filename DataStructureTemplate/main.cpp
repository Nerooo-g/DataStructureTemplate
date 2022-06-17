#include<iostream>
#include<fstream>
#include"HashMap.h"
#include"BinarySearchTree.h"
using namespace std;

void remove_number(string& str);
void add_dic(const string& str, HashMap<string, int>& map) {
    if (!map.search(str)) map.put(str, 1);
    else map.put(str, map.get(str) + 1);
}

void split_word(const string& str,HashMap<string,int>& map){
    string word = "";
    for (auto x : str) {
        if (x == ' ') {
            if (word != "") {
                remove_number(word);
                add_dic(word, map);
            }
            word = "";
        }
        else word = word + x;
    }
    remove_number(word);
    add_dic(word, map);
}

void remove_number(string& str) {
    auto it = str.begin();
    while (it != str.end()) {
        if ((*it) >= '1' && (*it) <= '9') it = str.erase(it);
        else it++;
    }
}

void dic(HashMap<string, int>& map,const string& path) {
    ifstream infile;
    infile.open(path, ios::in);
    string s;
    while (!infile.eof()) {
        getline(infile, s);
        s.erase(remove_if(s.begin(), s.end(), ispunct), s.end());
        split_word(s, map);
    }
}


void create(BST<int>* t) {
    /*int n = 5;
    for (n; n < 10; n++) {
        t->insert(n);
    }*/
    int n=0;
    while (cin >> n) {
        t->insert(n);
    }
}
/*int main() {
    BST<int>* t=new BST<int>(15);
    //t->insert(6);
    //t->insert(18);
    //t->insert(3);
    //t->insert(7);
    //t->insert(17);
    //t->insert(20);
    //t->insert(2);
    //t->insert(4);
    //t->insert(13);
    //t->insert(9);
    //t->remove(13);
    create(t);
    delete t;
    cin.get();
}*/

int main() {
    int n;
    while (cin >> n) {
        cout << n << endl;
    }
}
