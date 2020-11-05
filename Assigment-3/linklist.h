
//Linkedlist based on: https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
static ofstream fout("output.txt", ofstream::out);
struct node {
    string word;
    int count;
    struct node *next;
};

class List {
private:
    node *head, *tail;
    int size = 0;

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }
    ~List() {
        fout.close();
    }

    void createNode(string word);
    bool isEmpty();
    void printOut();
    void findWords(string word);
    int findOccurances(string word);
    void increaseCount(string word);
};

#endif