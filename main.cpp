#include "ItemTracker.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    ItemTracker tracker;
    
    // Load data from the input file and create a backup file
    tracker.loadData("CS210_Project_Three_Input_File.txt");
    tracker.backupData("frequency.dat");
    
    int choice;
    string searchTerm;
    
    // Menu loop for user interaction
    do {
        cout << "\nCorner Grocer Item Tracker Menu" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Input validation: Check for non-numeric input
        while (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input, please enter a number between 1 and 4: ";
            cin >> choice;
        }
        
        switch (choice) {
            case 1:
                cout << "Enter item to search: ";
                cin >> searchTerm;
                cout << "Frequency of " << searchTerm << " is: " << tracker.searchItem(searchTerm) << endl;
                break;
            case 2:
                cout << "Item Frequencies: " << endl;
                tracker.printFrequencies();
                break;
            case 3:
                cout << "Histogram: " << endl;
                tracker.printHistogram();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a number between 1 and 4." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
