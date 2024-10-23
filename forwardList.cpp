#include "forwardList.h"

void flistInitiate(string query, string fileName){
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

    fList* fl = new fList();
    if (filesystem::exists(fileName)){
        ifstream fin (fileName);
        string line;
        getline(fin, line);
        fin.close();

        stringstream ss(line);
        string elem;

        while (getline(ss, elem, ' ')){
            fl->push_back(elem);
        }
    }else{
        ofstream file(fileName);
        file.close();
    }
    if (action == "pushh") {fl->insert(value);}
    else if (action == "pusht") {fl->push_back(value);}
    else if (action == "delh") {fl->remove_head();}
    else if (action == "delt") {fl->remove_tail();}
    else if (action == "del") {fl->remove(value);}
    else if (action == "get") {
        if (fl->find(value) != nullptr) cout << "true" << endl;
        else cout << "false" << endl;
    }else{
        cout << "Action is not defined. " << endl;
        return;
    }
    fl->write(fileName);
    return;
}