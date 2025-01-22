//symtable_test.cpp
#include <gtest/gtest.h>
#include "symtable.h"

class SymTableTest : public :: testing ::Test{
protected:
    SymTable symtable = SymTable();
    void SetUp() {
        symtable.SymTable_put("var1","int");
        symtable.SymTable_put("var2","char");
        symtable.SymTable_put("var3","float");
        symtable.SymTable_put("var4","bool");
    }
};
    

TEST_F(SymTableTest, Milestone1){
//new,free,getlength
EXPECT_EQ(symtable.SymTable_getLength(),4);
}

TEST_F(SymTableTest, Milestone2){
//contains,put,get
EXPECT_EQ(symtable.SymTable_get("var1"),"int");
EXPECT_EQ(symtable.SymTable_get("var4"),"bool");

EXPECT_TRUE(symtable.SymTable_contains("var1"));
EXPECT_FALSE(symtable.SymTable_contains("var4"));
}

TEST_F(SymTableTest, Milestone3){
//remove
EXPECT_EQ(symtable.SymTable_remove("var1"),"Deleted");
EXPECT_EQ(symtable.SymTable_get("var1"),"Not Found");

EXPECT_EQ(symtable.SymTable_remove("var6"),"Key Not found");
}

TEST_F(SymTableTest, Milestone4){
//replace  
EXPECT_EQ(symtable.SymTable_replace("var1","char"),"Replaced");
EXPECT_EQ(symtable.SymTable_replace("var5","char"),"Key Not found");
EXPECT_EQ(symtable.SymTable_get("var1"),"char");

symtable.SymTable_replace("var5","char");
EXPECT_EQ(symtable.SymTable_get("var1"),"char");

}