#include <iostream>
#include "forwardList.h"
using namespace std;

int main(){
    string data = "check";
    fList* check = new fList();
    check->push_back(data);
    check->print();
    return 0;
}