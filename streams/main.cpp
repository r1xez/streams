#include <iostream>
#include "Directory.h"

using namespace std; 

int main() {
    const string filename = "directory.txt";

   
    vector<Directory> entries = Directory::loadEntries(filename);

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add new entry" << endl;
        cout << "2. Search by company name" << endl;
        cout << "3. Search by owner" << endl;
        cout << "4. Search by phone" << endl;
        cout << "5. Search by activity" << endl;
        cout << "6. Display all entries" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        cin.ignore();  

        if (option == 1) {
            string companyName, owner, phone, address, activity;
            cout << "Enter company name: ";
            getline(cin, companyName);
            cout << "Enter owner: ";
            getline(cin, owner);
            cout << "Enter phone: ";
            getline(cin, phone);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter activity: ";
            getline(cin, activity);

            Directory newEntry(companyName, owner, phone, address, activity);
            Directory::addEntry(newEntry, filename);
            entries.push_back(newEntry);

        }
        else if (option == 2) {
            string name;
            cout << "Enter company name to search: ";
            getline(cin, name);
            Directory::searchByName(entries, name);

        }
        else if (option == 3) {
            string owner;
            cout << "Enter owner name to search: ";
            getline(cin, owner);
            Directory::searchByOwner(entries, owner);

        }
        else if (option == 4) {
            string phone;
            cout << "Enter phone number to search: ";
            getline(cin, phone);
            Directory::searchByPhone(entries, phone);

        }
        else if (option == 5) {
            string activity;
            cout << "Enter activity to search: ";
            getline(cin, activity);
            Directory::searchByActivity(entries, activity);

        }
        else if (option == 6) {
            Directory::displayAllEntries(entries);

        }
        else if (option == 7) {
            break;

        }
        else {
            cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}
