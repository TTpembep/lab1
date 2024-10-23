#include "doublyLinkedList.h"

void dllistInitiate(string query, string fileName){
    fileName = "containers/" + fileName;
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
    dlList* dll = new dlList();
    if (filesystem::exists(fileName)){
        ifstream fin (fileName);
        string line;
        getline(fin, line);
        fin.close();

        stringstream ss(line);
        string elem;

        while (getline(ss, elem, ' ')){
            dll->push_back(elem);
        }
    }else{
        ofstream file(fileName);
        file.close();
    }
    if (action == "pushh") {dll->insert(value);}
    else if (action == "pusht") {dll->push_back(value);}
    else if (action == "delh") {dll->remove_head();}
    else if (action == "delt") {dll->remove_tail();}
    else if (action == "del") {dll->remove(value);}
    else if (action == "get") {
        if (dll->find(value) != nullptr) cout << "true" << endl;
        else cout << "false" << endl;
    }else{
        cout << "Action is not defined. " << endl;
        return;
    }
    dll->write(fileName);
    if (emptyFile(fileName)) filesystem::remove(fileName);
    return;
}