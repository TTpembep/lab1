#include "array.h"
#include "forwardList.h"
#include "doublyLinkedList.h"

int main(int argc, char* argv[]){
    // argv[0] = ./dbms
    string query = argv[1];  // argv[1] = --file
    if (query != "--file"){   
        cout << "Syntaxys error. " << endl;
        return 0;
    }
    string fileName = argv[2];  // argv[2] = flist.data
    if (fileName.find(".data") == string::npos){
        cout << "Wrong file name. " << endl;
        return 0;
    }
    query = argv[3]; // argv[3] = --query
    if (query != "--query"){   
        cout << "Syntaxys error. " << endl;
        return 0;
    }
    query = argv[4]; // argv[4] = 'FPUSH value'
    char structType = query[0];
    query.erase(0,1);
    if (structType == 'M'){
        arrayInitiate(query, fileName);
    }if (structType == 'F'){
        flistInitiate (query, fileName);
    }if (structType == 'L'){
        dllistInitiate (query, fileName);
    }
    // Реализовать universum print
    return 0;
}
/*
g++ main.cpp forwardList.cpp doublyLinkedList.cpp array.cpp -o dbms
./dbms --file flist.data --query 'FPUSHH value'
./dbms --file flist.data --query 'FDELT'
./dbms --file dllist.data --query 'LPUSHT toy'
*/