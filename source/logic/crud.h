#ifndef CRUD_H
#define CRUD_H

#define MAX_RECORD_SIZE 256 // Maximum size of a record
#define INDEX_FILE "../indexing.txt"
#define DATA_FILE "../data.txt"

// Structure for a record
typedef struct {
    int id;
    char data[MAX_RECORD_SIZE];
} Record;

// CRUD function prototypes
int create_record(int id, const char* data);
Record* read_record(int id);
int update_record(int id, const char* new_data);
int delete_record(int id);

#endif
