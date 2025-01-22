#include<string>
using namespace std;

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

class SymTable{
    struct Node{
    string key;
    string value;
    Node *next;
    };

    Node *head;
    public:
        SymTable();
        ~SymTable();

        string SymTable_get(string key_search);

        bool SymTable_contains(string key_to_search);

        int SymTable_getLength();

        string SymTable_replace(string key_check, string val);

        void SymTable_put(string key_to_insert,string val);

        string SymTable_remove(string key_to_delete);

        void SymTable_display();
};

#endif