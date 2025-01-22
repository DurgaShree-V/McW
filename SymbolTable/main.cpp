//main.cpp
#include <iostream>
#include "symtable.h"

using namespace std;

int main(){
    SymTable symtable = SymTable();
    symtable.SymTable_put("var1","int");
    symtable.SymTable_put("var2","char");
    symtable.SymTable_display();
    int no_of_entries = symtable.SymTable_getLength();
    cout << "No of entries in syymbol table are " << no_of_entries << endl;
    cout << "The key var1 is " << symtable.SymTable_remove("var1") << " from symbol table" << endl;
    symtable.SymTable_display();
    no_of_entries = symtable.SymTable_getLength();
    cout << "No of entries in symbol table are " << no_of_entries << endl;
    cout << "The key var2 and value char is " << (symtable.SymTable_contains("var2") == 1 ? "found" : "Not found") <<" in SymbolTable" << endl;
}