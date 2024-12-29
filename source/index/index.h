#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include <stdlib.h>

// Structure for an index entry
typedef struct {
    int id;
    long position;
} IndexEntry;

// Index management function prototypes
int add_index(int id, long position);
long get_position(int id);
int remove_index(int id);
void load_index();
void save_index();

#endif