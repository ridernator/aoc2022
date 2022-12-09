#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#define INPUT "../data/input"

/**
 * Read a file entirely into a stringstream
 * 
 * @param The name of the file to read
 * @return The contents of the file
 **/
std::stringstream readFile(const std::string& filename = INPUT) {
    std::ifstream fileStream(filename);
    std::stringstream returnVal;
    
    returnVal << fileStream.rdbuf();

    return returnVal;
}

/**
 * Read a file entirely into a vector of strings
 * 
 * @param The name of the file to read
 * @return The vector of lines in the file
 **/
std::vector<std::string> readFileToVector(const std::string& filename = INPUT) {
    std::ifstream fileStream(filename);
    std::string string;
    std::vector<std::string> returnVal;
    
    while (std::getline(fileStream, string)) {
        returnVal.push_back(string);
    }

    return returnVal;
}

bool containsDup(const std::string& test) {
    for (size_t index1 = 0; index1 < test.size() - 1; ++index1) {
        for (size_t index2 = index1 + 1; index2 < test.size(); ++index2) {
            if (test[index1] == test[index2]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::string data = readFile().str();

    for (size_t index = 0; index < data.size() - 4; ++index) {
        if (!containsDup(data.substr(index, 4))) {
            std::cout << "Found at " << (index + 4) << std::endl;

            break;
        }
    }

    return 0;
}
