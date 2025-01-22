Symbol Table Implementation

Overview
  This project implements a simple Symbol Table in C++ using a linked list structure. The symbol table stores key-value pairs, providing functionalities to add, retrieve, update, and remove entries. It can be used to manage variables and their data types or values in compiler or interpreter contexts.

Features
  Insert (put): Add a key-value pair to the symbol table. If the key already exists, the value is replaced.
  Search (get): Retrieve the value associated with a given key.
  Check Existence (contains): Verify if a key-value pair exists in the table.
  Remove: Delete a key-value pair from the table.
  Display: Print all entries in the symbol table.
  Length: Get the total number of entries in the symbol table.
  Replace: Update the value for a specific key if the key already exists.

Project Structure - Files
  symtable.h --> Header file defining the SymTable class and its methods.

  symtable_link.cpp --> Implementation of the SymTable class methods using a linked list structure.

  main.cpp --> Contains the main function demonstrating the usage of the SymTable class.

  symtable_test.cpp --> Contains unit tests for the SymTable class using Google Test framework.

  CMakeLists.txt --> CMake configuration file to build the project.

How to Build and Run

  Prerequisites
    A C++ compiler supporting C++11 or higher.
    CMake version 3.1 or higher.
    Google Test framework (gtest).

  Steps
    git clone <repository-url>
    cd <project-directory>
    mkdir build && cd build
    cmake ..
    make
    ./main

  This runs the main program demonstrating the functionality of the symbol table.

Run the Test File
  Make sure Google Test is installed.
  Steps
    make
    ./symtable_test
This will run the tests defined in the symtable_test.cpp file. It checks various functionalities of the SymTable class such as insert, replace, remove, and length checking.

Exepected Output
Running the test file will produce output similar to this:

[ RUN      ] SymTableTest.Milestone1
[       OK ] SymTableTest.Milestone1 (0 ms)
[ RUN      ] SymTableTest.Milestone2
[       OK ] SymTableTest.Milestone2 (0 ms)
[ RUN      ] SymTableTest.Milestone3
[       OK ] SymTableTest.Milestone3 (0 ms)
[ RUN      ] SymTableTest.Milestone4
[       OK ] SymTableTest.Milestone4 (0 ms)

Key Updates:
Insert Key: If a key already exists in the symbol table, its value is updated instead of adding a duplicate entry.
Node Deletion: The logic for removing a key-value pair from the table has been improved to handle edge cases more effectively.
Updated Features: New features, such as replacing values for existing keys and providing more useful feedback for certain operations.
