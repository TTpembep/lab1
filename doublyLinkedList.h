#ifndef INCLUDE_DOUBLYLINKEDLLIST_H
#define INCLUDE_DOUBLYLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>   //Для проверки наличия файла
using namespace std;

struct dlNode {   //Структура данных для узла двусвязанного списка
    string data;
    dlNode* next;
    dlNode* prev;
    dlNode(const string& data) : data(data), next(nullptr), prev(nullptr) {}
};

struct dlList {  //Структура данных для двусвязанного списка
    dlNode* head;
    dlNode* tail;

    dlList() : head(nullptr), tail(nullptr) {}

    ~dlList() {  //Деструктор
        clear();
    }

    void insert(const string& data) {   //Добавление элемента в начало списка
        dlNode* newdlNode = new dlNode(data);
        if (head == nullptr) {
            head = newdlNode;
            tail = newdlNode;
        } else {
            newdlNode->next = head;
            head->prev = newdlNode;
            head = newdlNode;
        }
    }

    void push_back(const string& data) {//Добавление элемента в конец списка
        dlNode* newdlNode = new dlNode(data);
        if (head == nullptr) {
            head = newdlNode;
            tail = newdlNode;
        } else {
            newdlNode->prev = tail;
            tail->next = newdlNode;
            tail = newdlNode;
        }
    }

    dlNode* find(const string& data) {    //Поиск элемента в списке
        dlNode* current = head;
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
        dlNode* p = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete p;
    }

    void remove_tail() {    //Удаление последнего элемента
        if (head == nullptr) return;
        if (head == tail) {
            remove_head();
            return;
        }
        dlNode* p = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete p;
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
        dlNode* current = head->next;
        while (current != nullptr) {
            if (current->data == data) {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "This element does not exist" << endl;
    }

    void print() {  //Вывод всех элементов списка
        dlNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void write(const string& fileName) {  //Запись списка в файл
        ofstream fout(fileName);
        if (head == nullptr) return; // Проверка на пустой список
        dlNode* current = head;
        while (current != nullptr) {
            fout << current->data << " ";
            current = current->next;
        }
        fout.close();
    }

    void clear() {  //Освобождение памяти
        dlNode* current = head;
        while (current != nullptr) {
            dlNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    dlNode* operator[] (const int index) {    //Обращение по индексу
        if (head == nullptr) return nullptr;
        dlNode* p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

void dllistInitiate(string query, string fileName);
bool emptyFile (string fileName);

#endif