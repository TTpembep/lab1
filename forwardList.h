#ifndef INCLUDE_FORWARDLIST_H
#define INCLUDE_FORWARDLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct fNode {   //Структура данных для узла односвязанного списка
    string data;
    fNode* next;
    fNode(const string& data) : data(data), next(nullptr) {}
};
struct fList {  //Структура данных для односвязанного списка
    fNode* head;
    fNode* tail;

    fList() : head(nullptr), tail(nullptr) {}

    ~fList() {  //Деструктор
        clear();
    }

    void insert(const string& data) {   //Добавление элемента в начало списка
        fNode* newfNode = new fNode(data);
        newfNode->next = head;
        head = newfNode;
    }
    void push_back(const string& data) {//Добавление элемента в конец списка
        fNode* newfNode = new fNode(data);
        if (head == nullptr) {
            head = newfNode;
            tail = newfNode;
            return;
        }
        tail->next = newfNode;
        tail = newfNode;
    }
    fNode* find(const string& data) {    //Поиск элемента в списке
        fNode* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }    
    void remove_head() {   //Удаление первого элемента
        if (head == nullptr) return;
        fNode* p = head;
        head = p->next;
        delete p;
    }
    void remove_tail() {    //Удаление последнего элемента
        if (head == nullptr) return;
        if (head == tail) {
            remove_head();
            return;
        }
        fNode* p = head;
        while (p->next != tail) p = p->next;
        p->next = nullptr;
        delete tail;
        tail = p;
    }
    void remove(string data) {  //Удаление определённого элемента
        if (head == nullptr) return;
        if (head->data == data) {
            remove_head();
            return;
        }
        else if (tail->data == data) {
            remove_tail();
            return;
        }
        fNode* slow = head;
        fNode* fast = head->next;
        while (fast && fast->data != data) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
    void print() {  //Вывод всех элементов списка
        fNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void write(ofstream& fout) {  //Запись списка в файл
        if (head == nullptr) return; // Проверка на пустой список
        fNode* current = head;
        while (current != nullptr) {
            fout << current->data << " ";
            current = current->next;
        }
    }
    void clear() {  //Освобождение памяти
        fNode* current = head;
        while (current != nullptr) {
            fNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
    fNode* operator[] (const int index) {    //Обращение по индексу
        if (head == nullptr) return nullptr;
        fNode* p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

void flistInitiate(string query, string fileName);

#endif