#ifndef ASLISTR_H
#define ASLISTR_H

#include <string>
#include <iostream>
#include <algorithm>

struct CO2EmissionsRecord {
    std::string country;      // Country name
    int year;                 // Year of emissions data
    double CO2_emissions;     // CO2 emissions value for the country
};
class ASListR {
public:
    ASListR(int maxSize);      // Constructor with parameter for max array size
    ~ASListR();                // Destructor

    void PutItem(const CO2EmissionsRecord&); // Adds the item to the list
    void PrintList();          // Print all elements of the list in a readable format
    void SortByCO2EmissionsDescending();  // Sort the list by CO2 emissions in descending order
private:
    int length;                // Current number of items in the list
    CO2EmissionsRecord* ListItems; // Array of CO2EmissionsRecord
    int MAXSIZE;               // Maximum size of the list
    int currentPos;            // Current position in the list
};
// Constructor
ASListR::ASListR(int maxSize) {
    length = 0;
    MAXSIZE = maxSize;
    currentPos = 0;
    ListItems = new CO2EmissionsRecord[MAXSIZE];
}
// Destructor
ASListR::~ASListR() {
    delete[] ListItems;
}
// Adds an item to the list
void ASListR::PutItem(const CO2EmissionsRecord& record) {
    if (length < MAXSIZE) {
        ListItems[length] = record;
        length++;
    } else {
        std::cout << "Error: List is full!" << std::endl;
    }
}
// Print all elements of the list
void ASListR::PrintList() {
    for (int i = 0; i < length; i++) {
        std::cout << "Country: " << ListItems[i].country 
                  << ", Year: " << ListItems[i].year 
                  << ", CO2 Emissions: " << ListItems[i].CO2_emissions << std::endl;
    }
}
// Sort the list by CO2 emissions in descending order
void ASListR::SortByCO2EmissionsDescending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.CO2_emissions > b.CO2_emissions;  // Sort in descending order
    });
}

#endif
