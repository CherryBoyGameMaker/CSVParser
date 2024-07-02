#include "CSVParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

CSVParser::CSVParser(const std::string& filename) : filename(filename) {}

void CSVParser::readCSV() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        data.push_back(splitLine(line));
    }

    file.close();
}

void CSVParser::writeCSV(const std::string& outputFilename) {
    std::ofstream file(outputFilename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
}

const std::vector<std::vector<std::string>>& CSVParser::getData() const {
    return data;
}

void CSVParser::sortData(int columnIndex, bool ascending) {
    std::sort(data.begin(), data.end(), [columnIndex, ascending](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        if (ascending) {
            return a[columnIndex] < b[columnIndex];
        }
        else {
            return a[columnIndex] > b[columnIndex];
        }
        });
}

void CSVParser::filterData(int columnIndex, const std::string& value) {
    data.erase(std::remove_if(data.begin(), data.end(), [columnIndex, value](const std::vector<std::string>& row) {
        return row[columnIndex] != value;
        }), data.end());
}

void CSVParser::printData() const {
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i < row.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "\n";
    }
}

std::vector<std::string> CSVParser::splitLine(const std::string& line, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}
