#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

class ItemTracker {
private:
    // Map to store items and their frequency
    map<string, int> frequency;
public:
    // Load data from the file into the map
    void loadData(const string& filename);

    // Search for a item and return its frequency count
    int searchItem(const string& item);

    // print all items with their frequency counts
    void printFrequencies();

    // Print a histogram 
    void printHistogram();

    // Backup frequency data to a file
    void backupData(const string& backupFilename);
};

#endif
