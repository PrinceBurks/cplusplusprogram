#include "ItemTracker.h"
#include <fstream>
#include <iostream>
using namespace std;

void ItemTracker::loadData(const string& filename) {
    ifstream infile(filename);// Open the file for reading
    if (!infile) {// Check if the file was not opened successfully
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string item;
    // Read each word from the file and update its frequency
    while (infile >> item) {
        frequency[item]++;
    }
    infile.close();// Close the file after reading is complete
}
// Searches for a specific item in the frequency map and returns its count.
int ItemTracker::searchItem(const string& item) {
    if (frequency.find(item) != frequency.end()) {// Check if the item exists in the map
        return frequency[item];// Return the frequency if found
    }
    return 0;// Return 0 if the item is not found
}
// Outputs each item and its frequency count to the console.
void ItemTracker::printFrequencies() {
    for (const auto &pair : frequency) {// Iterate through each key-value pair in the frequency map
        cout << pair.first << " " << pair.second << endl;// Output the item (key) and its frequency (value)
    }
}

void ItemTracker::printHistogram() {// Outputs a histogram to the console where each item is followed by asterisks
    for (const auto &pair : frequency) {// Iterate through each key-value pair in the frequency map
        cout << pair.first << " ";// Output the item name
        for (int i = 0; i < pair.second; i++) {
            cout << "*";// Print an asterisk for each count of the item
        }
        cout << endl;
    }
}

void ItemTracker::backupData(const string& backupFilename) {// Writes the frequency map data to a backup file.
    ofstream outfile(backupFilename);// Open the file for writing
    if (!outfile) {// Check if the file was successfully created/opened
        cerr << "Error creating file: " << backupFilename << endl;
        return;
    }
    for (const auto &pair : frequency) { // Iterate through each key-value pair in the frequency map and write it to the file
        outfile << pair.first << " " << pair.second << endl;
    }
    outfile.close();// Close the file after writing is complete
}
