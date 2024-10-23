#include "forwardList.h"

void flistInitiate(string query, string fileName){
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
    fList* fl = new fList();
    string temp;
    while (fin >> temp) {
        fl->push_back(temp);
    }fin.close();
    if (action == "pushh") {fl->insert(value);}
    if (action == "pusht") {fl->push_back(value);}
    if (action == "delh") {fl->remove_head();}
    if (action == "delt") {fl->remove_tail();}
    if (action == "del") {fl->remove(value);}
    if (action == "get") {
        if (fl->find(value) != nullptr) cout << "true" << endl;
        else cout << "false" << endl;
    }
    ofstream fout("containers/" + fileName);
    if (!fout.is_open()) {
        cerr << "Unable to open file for writing" << endl;
        return;
    }
    fl->write(fout);
    fout.close();
    return;
}