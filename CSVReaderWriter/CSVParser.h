#pragma once

#include <vector>
#include <string>
using namespace std;
class CSVParser {
public:
    CSVParser(const string& filename);
    void readCSV();
    void writeCSV(const string& outputFilename);
    const vector<vector<string>>& getData() const;
    void sortData(int columnIndex, bool ascending = true);
    void filterData(int columnIndex, const string& value);
    void printData() const;

private:
    string filename;
    vector<vector<string>> data;

    vector<string> splitLine(const string& line, char delimiter = ',');
};
