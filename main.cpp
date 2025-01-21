#include <iostream>
#include "symtable.h"

using namespace std;

int main(){
    SymTable symtable = SymTable();
    symtable.SymTable_put("no1","Durga");
    symtable.SymTable_put("no2","Nithya");
    symtable.SymTable_display();
    int no_of_entries = symtable.SymTable_getLength();
    cout << "No of entries in syymbol table are " << no_of_entries << endl;
    symtable.SymTable_remove("no1");
    symtable.SymTable_display();
    no_of_entries = symtable.SymTable_getLength();
    cout << "No of entries in syymbol table are " << no_of_entries << endl;
}