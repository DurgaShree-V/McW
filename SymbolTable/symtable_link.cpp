#include <iostream>
#include "symtable.h"

using namespace std;

SymTable::SymTable(){
    head = NULL;
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

int SymTable::SymTable_getLength(){
    int len = 0;
    Node *temp = head; 
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void SymTable::SymTable_replace(string key_check, string val){
    Node *temp = head;
    while(temp!=NULL){
        if(temp->key == key_check){
            temp->value = val;
        }
        temp = temp->next;
    }
}

void SymTable::SymTable_put(string key_to_insert, string val){
    Node *temp = head;
    Node *newNode = new Node();
    newNode->key = key_to_insert;
    newNode->value = val;
    newNode->next = NULL;
    if(head ==  NULL){
        head = newNode;
        return;
    }
    else{
        while(temp->next!=NULL){
            if(temp->key == key_to_insert){
                temp->value = val;
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void SymTable::SymTable_remove(string key_to_delete){
    Node *temp = head;
    Node *del_node = NULL;
    Node *prev = temp;
    if(head->key == key_to_delete){
        del_node = head;
        head = head->next;
    }
    else{
        while(temp!=NULL){
            if(temp->key == key_to_delete){
                cout << "The value at " << temp->key << " is " << temp->value << endl;
                del_node = temp->next;
                prev->next = temp->next->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        delete del_node;   
    }
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
