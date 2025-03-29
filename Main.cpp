#include "ASListR.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ASListR csvtoASListR(string csvfile) { // Convert a csv file to a list structure
    ASListR retCO2List(205); // Make sure the array has sufficient size for our data
    ifstream ReadFile(csvfile); // Open the csv file for reading
    string line, curvalue;
    getline(ReadFile, line); // Skip the first line (column names)
    
    while (getline(ReadFile, line)) {
        stringstream ss(line); // Turn the line into a string-stream
        int fielditer = 0;
        CO2EmissionsRecord newrec;
        
        // Parse each field in the CSV line
        while (getline(ss, curvalue, ',')) {
            switch (fielditer) {
                case 0: newrec.country = curvalue; break;    // Country name
                case 1: newrec.year = stoi(curvalue); break;  // Year
                case 2: newrec.CO2_emissions = stod(curvalue); break;  // CO2 emissions (numeric)
            }
            fielditer++;
        }
        
        retCO2List.PutItem(newrec); // Add the record to the list
    }
    
    return retCO2List; // Return the populated ASListR
}

int main(int argc, char** argv) {
    // Load CO2 emissions data from CSV file
    ASListR CO2EmissionsData = csvtoASListR("CO2_Emissions.csv");
    
    // Sort the data by CO2 emissions in descending order
    CO2EmissionsData.SortByCO2EmissionsDescending();
    
    // Print the sorted data
    CO2EmissionsData.PrintList(); // Ensure the list is printed in the correct order
    return 0;
}
