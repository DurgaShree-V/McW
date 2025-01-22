# Symbol Table Implementation

## Overview

This project implements a simple **Symbol Table** in C++ using a linked list structure. The symbol table stores key-value pairs, providing functionalities to add, retrieve, update, and remove entries. It can be used to manage variables and their data types or values in compiler or interpreter contexts.

## Features

- **Insert (put):** Add a key-value pair to the symbol table. If the key already exists, the value is replaced.
- **Search (get):** Retrieve the value associated with a given key.
- **Check Existence (contains):** Verify if a key-value pair exists in the table.
- **Remove:** Delete a key-value pair from the table.
- **Display:** Print all entries in the symbol table.
- **Length:** Get the total number of entries in the symbol table.
- **Replace:** Update the value for a specific key if the key already exists.

## Project Structure - Files

- **symtable.h**  
  Header file defining the `SymTable` class and its methods.

- **symtable_link.cpp**  
  Implementation of the `SymTable` class methods using a linked list structure.

- **main.cpp**  
  Contains the main function demonstrating the usage of the `SymTable` class.

- **symtable_test.cpp**  
  Contains unit tests for the `SymTable` class using the Google Test framework.

- **CMakeLists.txt**  
  CMake configuration file to build the project.

## How to Build and Run

### Prerequisites

- A C++ compiler supporting C++11 or higher.
- CMake version 3.1 or higher.
- Google Test framework (gtest).

### Steps

1. Clone the repository:
    ```bash
    git clone <repository-url>
    ```

2. Navigate to the project directory:
    ```bash
    cd <project-directory>
    ```

3. Create a build directory and navigate to it:
    ```bash
    mkdir build && cd build
    ```

4. Run CMake to configure the build:
    ```bash
    cmake ..
    ```

5. Build the project:
    ```bash
    make
    ```

6. Run the executable:
    ```bash
    ./main
    ```

This runs the main program demonstrating the functionality of the symbol table.

## Run the Test File

### Steps

1. Make sure **Google Test** is installed.
2. After building the project, run the test file:
    ```bash
    make
    ./symtable_test
    ```

This will run the tests defined in the `symtable_test.cpp` file. It checks various functionalities of the `SymTable` class such as insert, replace, remove, and length checking.

### Expected Output

Running the test file will produce output similar to this:
```bash
[ RUN      ] SymTableTest.Milestone1
[       OK ] SymTableTest.Milestone1 (0 ms)
[ RUN      ] SymTableTest.Milestone2
[       OK ] SymTableTest.Milestone2 (0 ms)
[ RUN      ] SymTableTest.Milestone3
[       OK ] SymTableTest.Milestone3 (0 ms)
[ RUN      ] SymTableTest.Milestone4
[       OK ] SymTableTest.Milestone4 (0 ms)
 ```

