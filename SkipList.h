#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node** forward;
    Node(int key, int level) {
        this->key = key;
        forward = new Node * [static_cast<__int64>(level) + 1];
        memset(forward, 0, sizeof(Node*) * (static_cast<__int64>(level) + 1));
    }
};

class SkipList
{
    int MAXLVL;
    float P;
    int level;
    Node* header;
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    void displayList();
    int searchKey(int);
};