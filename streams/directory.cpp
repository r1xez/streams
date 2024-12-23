#include "Directory.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std; 


Directory::Directory(const string& companyName, const string& owner, const string& phone, const string& address, const string& activity)
    : companyName(companyName), owner(owner), phone(phone), address(address), activity(activity) {}


string Directory::getCompanyName() const { return companyName; }
string Directory::getOwner() const { return owner; }
string Directory::getPhone() const { return phone; }
string Directory::getAddress() const { return address; }
string Directory::getActivity() const { return activity; }


void Directory::display() const {
    cout << "Company Name: " << companyName << endl;
    cout << "Owner: " << owner << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
    cout << "Activity: " << activity << endl;
    cout << "----------------------------" << endl;
}


void Directory::addEntry(const Directory& entry, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << entry.getCompanyName() << ", "
            << entry.getOwner() << ", "
            << entry.getPhone() << ", "
            << entry.getAddress() << ", "
            << entry.getActivity() << endl;
        file.close();
    }
    else {
        cout << "Error: Could not open file for writing." << endl;
    }
}


vector<Directory> Directory::loadEntries(const string& filename) {
    ifstream file(filename);
    vector<Directory> entries;
    string companyName, owner, phone, address, activity;

    if (file.is_open()) {
        while (getline(file, companyName, ',') &&
            getline(file, owner, ',') &&
            getline(file, phone, ',') &&
            getline(file, address, ',') &&
            getline(file, activity)) {
            entries.push_back(Directory(companyName, owner, phone, address, activity));
        }
        file.close();
    }
    else {
        cout << "Error: Could not open file for reading." << endl;
    }
    return entries;
}


void Directory::searchByName(const vector<Directory>& entries, const string& name) {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.getCompanyName() == name) {
            entry.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with the company name: " << name << endl;
    }
}


void Directory::searchByOwner(const vector<Directory>& entries, const string& owner) {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.getOwner() == owner) {
            entry.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with the owner: " << owner << endl;
    }
}


void Directory::searchByPhone(const vector<Directory>& entries, const string& phone) {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.getPhone() == phone) {
            entry.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with the phone number: " << phone << endl;
    }
}


void Directory::searchByActivity(const vector<Directory>& entries, const string& activity) {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.getActivity() == activity) {
            entry.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No entries found with the activity: " << activity << endl;
    }
}


void Directory::displayAllEntries(const vector<Directory>& entries) {
    for (const auto& entry : entries) {
        entry.display();
    }
}
