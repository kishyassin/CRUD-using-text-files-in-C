# CRUD Application

This project is a simple CRUD (Create, Read, Update, Delete) application implemented in C++. It allows users to manage records with an interactive menu. The records are stored in a text file, and an index file is used to keep track of the positions of the records.

## Features

- **Create Record**: Add a new record with an ID and data.
- **Read Record**: Retrieve a record by its ID.
- **Update Record**: Modify the data of an existing record.
- **Delete Record**: Remove a record by its ID.
- **Persistent Storage**: Records and their indices are stored in text files.

## File Structure

- `source/main.cpp`: Contains the main function and the interactive menu.
- `source/logic/crud.cpp`: Implements the CRUD operations.
- `source/logic/crud.h`: Declares the CRUD operations and defines the `Record` structure.
- `source/index/index.cpp`: Manages the index of records.
- `source/index/index.h`: Declares the index management functions and defines the `IndexEntry` structure.
- `indexing.txt`: Stores the index of records.
- `data.txt`: Stores the actual records.


### Prerequisites

- C++ compiler (supporting C++20)
- CMake (version 3.29 or higher)


## Contributions

Contributions are welcome!For feature requests and bug reports

