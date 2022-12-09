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

uint32_t letterToNumber(const char letter) {
    if (letter < 'a') {
        return letter - 38;
    } else {
        return letter - 96;
    }
}

int main() {
    auto lines = readFileToVector();
    uint32_t total = 0;

    for (const auto& line : lines) {
        uint32_t halfWidth = line.size() / 2;
        std::string compartment1 = line.substr(0, halfWidth);
        std::string compartment2 = line.substr(halfWidth);
        std::sort(compartment1.begin(), compartment1.end());
        std::sort(compartment2.begin(), compartment2.end());
     
        std::string intersection;
     
        std::set_intersection(compartment1.begin(), compartment1.end(),
                              compartment2.begin(), compartment2.end(),
                              std::back_inserter(intersection));

        if (!intersection.empty()) {
            total += letterToNumber(intersection[0]);
        }
    }

    std::cout << "Sum is " << total << std::endl;

    return 0;
}
