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

int main() {
    auto lines = readFileToVector();
    uint32_t count = 0;

    for (const auto& line : lines) {
        uint32_t range1Num1;
        uint32_t range1Num2;
        uint32_t range2Num1;
        uint32_t range2Num2;

        sscanf(line.c_str(), "%u-%u,%u-%u", &range1Num1, &range1Num2, &range2Num1, &range2Num2);

        if (((range1Num1 <= range2Num1) && (range1Num2 >= range2Num2)) ||
            ((range1Num1 >= range2Num1) && (range1Num2 <= range2Num2))) {
            ++count;
        }
    }

    std::cout << "Num pairs which match : " << count << std::endl;

    return 0;
}
