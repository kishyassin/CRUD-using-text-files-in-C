#include "index.h"
#include "../logic/crud.h"

#define MAX_INDEX_ENTRIES 100

static IndexEntry index_table[MAX_INDEX_ENTRIES];
static int index_count = 0;

int add_index(int id, long position) {
    index_table[index_count].id = id;
    index_table[index_count].position = position;
    index_count++;
    return 0;
}

long get_position(int id) {
    for (int i = 0; i < index_count; i++) {
        if (index_table[i].id == id) {
            return index_table[i].position;
        }
    }
    return -1; // Not found
}

int remove_index(int id) {
    for (int i = 0; i < index_count; i++) {
        if (index_table[i].id == id) {
            for (int j = i; j < index_count - 1; j++) {
                index_table[j] = index_table[j + 1];
            }
            index_count--;
            return 0;
        }
    }
    return -1; // Not found
}

void load_index() {
    FILE* file = fopen(INDEX_FILE, "r");
    if (file) {
        index_count = 0;
        while (fscanf(file, "%d %ld", &index_table[index_count].id, &index_table[index_count].position) == 2) {
            index_count++;
        }
        fclose(file);
    }
}

void save_index() {
    FILE* file = fopen(INDEX_FILE, "w");
    if (file) {
        for (int i = 0; i < index_count; i++) {
            fprintf(file, "%d %ld\n", index_table[i].id, index_table[i].position);
        }
        fclose(file);
    }
}
