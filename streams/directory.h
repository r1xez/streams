#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>

using namespace std; 

class Directory {
private:
    string companyName;
    string owner;
    string phone;
    string address;
    string activity;

public:
  
    Directory(const string& companyName, const string& owner, const string& phone, const string& address, const string& activity);

    
    string getCompanyName() const;
    string getOwner() const;
    string getPhone() const;
    string getAddress() const;
    string getActivity() const;

 
    void display() const;

   
    static void addEntry(const Directory& entry, const string& filename);
    static vector<Directory> loadEntries(const string& filename);

    static void searchByName(const vector<Directory>& entries, const string& name);
    static void searchByOwner(const vector<Directory>& entries, const string& owner);
    static void searchByPhone(const vector<Directory>& entries, const string& phone);
    static void searchByActivity(const vector<Directory>& entries, const string& activity);

    static void displayAllEntries(const vector<Directory>& entries);
};

#endif 
