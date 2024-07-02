#include <iostream>
#include "CSVParser.h"

int main() {
    try {
        cout << "Please enter filename " << endl;
        string filename = "";
        cin >> filename;

        CSVParser parser(filename);
        parser.readCSV();

        cout << "Choose an option:"<<endl;
        cout << "1. Print original data" << endl;
        cout << "2. Sort data by column" << endl;
        cout << "3. Filter data by value" << endl;
        int chooser = 0;
        cin >> chooser;

        switch (chooser)
        {
        case 1:
        {
             cout << "Original Data:\n";
            parser.printData();
            break;
        }
        case 2:
        {
            cout << "Enter the column number " << endl;
            int columnNumber=0;
            cin >> columnNumber;
            parser.sortData(columnNumber);
            cout << "\nSorted Data:\n";
            parser.printData();
            break;
        }
        case 3:
        {
            cout << "Enter the column number " << endl;
            int columnNumber = 0;
            cin >> columnNumber;
            cout << "Enter the column filter " << endl;
            string columnFilter = "";
            cin >> columnFilter;
            parser.filterData(columnNumber, columnFilter);
             cout << "\nFiltered Data:\n";
            parser.printData();
            break;
        }
        default:
            cout << "Invalid operation" << endl;
            break;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
    }


    return 0;
}