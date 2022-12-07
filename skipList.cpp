#include "SkipList.h"
#include <iostream>
#include <vector>
using namespace std;

SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;
    header = new Node(-1, MAXLVL);
};

int SkipList::randomLevel()
{
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
};

Node* SkipList::createNode(int key, int level)
{
    Node* n = new Node(key, level);
    return n;
};

void SkipList::insertElement(int key)
{
    Node* current = header;
    vector<Node*> update;
    update.resize(static_cast<__int64>(MAXLVL) + 1);
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != NULL &&
            current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || current->key != key)
    {
        int rlevel = randomLevel();
        if (rlevel > level)
        {
            for (int i = level + 1; i < rlevel + 1; i++)
                update[i] = header;
            level = rlevel;
        }
        Node* n = createNode(key, rlevel);
        for (int i = 0; i <= rlevel; i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout << "Successfully Inserted key " << key << "\n";
    }
};

void SkipList::displayList()
{
    cout << "\n*****Skip List*****" << "\n";
    for (int i = 0; i <= level; i++)
    {
        Node* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != NULL)
        {
            cout << node->key << " ";
            node = node->forward[i];
        }
        cout << "\n";
    }
};

int SkipList::searchKey(int index) {
    cout << "\n*****Key with index "<< index << "*****" << "\n";
    Node* node = header->forward[0];
    int i = 0;
    while (node != NULL)
    {
        if (i == index) {
            return node->key;
        }
        node = node->forward[0];
        i++;
    }
    cout << "\nThere is no key with index: " << index;
}
