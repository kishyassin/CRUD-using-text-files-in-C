#include "logic/crud.h"
#include "index/index.h"
#include <iostream>

void display_menu() {
    std::cout << "1. Create Record\n";
    std::cout << "2. Read Record\n";
    std::cout << "3. Update Record\n";
    std::cout << "4. Delete Record\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    load_index();
    int choice, id;
    char data[MAX_RECORD_SIZE];

    while (true) {
        display_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cin.ignore(); // Ignore newline character
                std::cout << "Enter Data: ";
                std::cin.getline(data, MAX_RECORD_SIZE);
                if (create_record(id, data) == 0) {
                    std::cout << "Record created successfully.\n";
                } else {
                    std::cout << "Failed to create record.\n";
                }
                break;
            case 2:
                std::cout << "Enter ID: ";
                std::cin >> id;
                Record* record;
                record = read_record(id);
                if (record) {
                    std::cout << "Record ID: " << record->id << ", Data: " << record->data << "\n";
                    free(record);
                } else {
                    std::cout << "Record not found.\n";
                }
                break;
            case 3:
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cin.ignore(); // Ignore newline character
                std::cout << "Enter New Data: ";
                std::cin.getline(data, MAX_RECORD_SIZE);
                if (update_record(id, data) == 0) {
                    std::cout << "Record updated successfully.\n";
                } else {
                    std::cout << "Failed to update record.\n";
                }
                break;
            case 4:
                std::cout << "Enter ID: ";
                std::cin >> id;
                if (delete_record(id) == 0) {
                    std::cout << "Record deleted successfully.\n";
                } else {
                    std::cout << "Failed to delete record.\n";
                }
                break;
            case 5:
                save_index();
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}