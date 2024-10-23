#ifndef INCLUDE_QUEUE_H
#define INCLUDE_QUEUE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>   //Для проверки наличия файла
using namespace std;

struct qNode {
        string data;
        qNode* next;
        qNode* prev;
        qNode(const string& value) : data(value), next(nullptr), prev(nullptr) {}
    };

struct Queue {
    qNode* head;
    qNode* tail;

    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        while (head != nullptr) {
            qNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const string& value) {
        qNode* newqNode = new qNode(value);
        if (tail == nullptr) {
            head = tail = newqNode;
        } else {
            tail->next = newqNode;
            newqNode->prev = tail;
            tail = newqNode;
        }
    }

    void remove() {
        qNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void write(const string& filename) {
        ofstream fout(filename);
        qNode* current = head;
        while (current != nullptr) {
            fout << current->data;
            if (current->next != nullptr) {
                fout << " ";
            }
            current = current->next;
        }
        fout.close();
    }
};

void queueInitiate(string query, string fileName);
bool emptyFile (string fileName);

#endif