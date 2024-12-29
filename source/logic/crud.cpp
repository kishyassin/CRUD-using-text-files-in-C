#include "crud.h"
#include "../index/index.h"

int create_record(int id, const char* data) {
    FILE* data_file = fopen(DATA_FILE, "r+");
    if (!data_file) return -1;

    fseek(data_file, 0, SEEK_END); // Move to the end of the file
    long position = ftell(data_file); // Get the current file position
    fprintf(data_file, "%d %s\n", id, data);
    fclose(data_file);

    add_index(id, position);
    save_index();
    return 0;
}

Record* read_record(int id) {
    long position = get_position(id);
    if (position == -1) return NULL;

    FILE* data_file = fopen(DATA_FILE, "r");
    if (!data_file) return NULL;

    fseek(data_file, position, SEEK_SET);
    Record* record = (Record*)malloc(sizeof(Record));
    fscanf(data_file, "%d %[^\n]", &record->id, record->data);
    fclose(data_file);

    return record;
}

int update_record(int id, const char* new_data) {
    long position = get_position(id);
    if (position == -1) return -1;

    delete_record(id);
    return create_record(id, new_data);
}

int delete_record(int id) {
    if (remove_index(id) == -1) return -1;
    save_index();
    return 0; // Logical deletion only
}
