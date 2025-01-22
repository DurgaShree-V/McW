//symtable_link.cpp
#include <iostream>
#include "symtable.h"

using namespace std;

SymTable::SymTable(){
    head = NULL;
}

SymTable::~SymTable(){
    Node *del_node = NULL;
    while(head!=NULL){
        del_node = head;
        head = head->next;
        delete del_node;
    }
}

string SymTable::SymTable_get(string key_search){
    Node *temp = head;
    while(temp!=NULL){
        if(temp->key == key_search){
            return temp->value;
        }
        temp = temp->next;
    }
    return "Not Found";
}

bool SymTable::SymTable_contains(string key_to_search){
    Node *temp = head;
    while(temp!=NULL){
        if(temp->key == key_to_search){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int SymTable::SymTable_getLength(){
    int len = 0;
    Node *temp = head; 
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

string SymTable::SymTable_replace(string key_check, string val){
    Node *temp = head;
    while(temp!=NULL){
        if(temp->key == key_check){
            temp->value = val;
            return "Replaced";
        }
        temp = temp->next;
    }
    return "Key Not found";
}

void SymTable::SymTable_put(string key_to_insert, string val){
    Node *temp = head;

    Node *newNode = new Node();
    newNode->key = key_to_insert;
    newNode->value = val;
    newNode->next = NULL;

    if(head ==  NULL){
        head = newNode;
    }
    else{
        if(SymTable_contains(key_to_insert)==1){
            cout << "Already exists" << endl;
            return;
        }
        while(temp!=NULL){
            temp = temp ->next;
        }
        temp = newNode;
        delete newNode;
    }
}

string SymTable::SymTable_remove(string key_to_delete){
    Node *temp = head;
    Node *prev = NULL;

    if(head!=NULL && head->key == key_to_delete){
        head = head->next;
        delete temp;
        return "Deleted";
    }
    else{
        while(temp!=NULL){
            if(temp->key == key_to_delete){
                //cout << "The value at " << temp->key << " is " << temp->value << endl;
                prev->next = temp->next->next;
                delete temp;
                return "Deleted";
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return "Key Not found";
}

void SymTable::SymTable_display(){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    while(temp!=NULL){
        cout <<"|" << temp->key << "|" << temp->value << "| --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
