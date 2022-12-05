#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

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

    std::map<std::string, uint32_t> TABLE{{"A X", 3 + 0},
                                          {"A Y", 1 + 3},
                                          {"A Z", 2 + 6},
                                          {"B X", 1 + 0},
                                          {"B Y", 2 + 3},
                                          {"B Z", 3 + 6},
                                          {"C X", 2 + 0},
                                          {"C Y", 3 + 3},
                                          {"C Z", 1 + 6}
                                         };

    uint32_t score = 0;

    for (const auto& line : lines) {
        score += TABLE[line];
    }

    std::cout << "Score is " << score << std::endl;
}
