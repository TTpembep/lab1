#include "queue.h"

void queueInitiate(string query, string fileName){
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

    Queue* queue = new Queue();
    if (filesystem::exists(fileName)){
        ifstream fin (fileName);
        string line;
        getline(fin, line);
        fin.close();

        stringstream ss(line);
        string elem;

        while (getline(ss, elem, ' ')){
            queue->push(elem);
        }
    }else{
        ofstream file(fileName);
        file.close();
    }
    if (action == "push") {queue->push(value);}
    else if (action == "pop") {queue->remove();}
    else{
        cout << "Action is not defined. " << endl;
        return;
    }
    queue->write(fileName);
    if (emptyFile(fileName)) filesystem::remove(fileName);
    return;
}