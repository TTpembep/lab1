#include "doublyLinkedList.h"

void dllistInitiate(string query, string fileName){
    if (fileName != "dllist.data") {
        cout << "Wrong file name. " << endl;
        return;
    }
    stringstream ss (query);
    string action;
    getline(ss, action, ' ');
    string value;
    getline(ss, value);
    for (char &c : action) {
        if (isupper(c)) {
            c = tolower(c);
        }else {
            cout << "Action syntaxys error. " << endl;
            return;
        }
    }
    ifstream fin("containers/" + fileName);
    if (!fin.is_open()) {
        cerr << "Unable to open file for reading" << endl;
        return;
    }
    dlList* dll = new dlList();
    string temp;
    while (fin >> temp) {
        dll->push_back(temp);
    }fin.close();
    if (action == "pushh") {dll->insert(value);}
    if (action == "pusht") {dll->push_back(value);}
    if (action == "delh") {dll->remove_head();}
    if (action == "delt") {dll->remove_tail();}
    if (action == "del") {dll->remove(value);}
    if (action == "get") {
        if (dll->find(value) != nullptr) cout << "true" << endl;
        else cout << "false" << endl;
    }
    ofstream fout("containers/" + fileName);
    if (!fout.is_open()) {
        cerr << "Unable to open file for writing" << endl;
        return;
    }
    dll->write(fout);
    fout.close();
    return;
}