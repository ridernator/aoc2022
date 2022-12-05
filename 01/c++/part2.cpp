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
    std::vector<uint32_t> calories;
    uint32_t tempCals = 0;

    for (const auto& line : lines) {
        if (line.empty()) {
            calories.push_back(tempCals);

            tempCals = 0;
        } else {
            tempCals += std::stoi(line);
        }
    }

    std::sort(calories.begin(), calories.end(), std::greater<int>());

    std::cout << "Top 3 elves carry (" << calories[0] << " + " << calories[1] << " + " << calories[2] << ") + " << (calories[0] + calories[1] + calories[2]) << " calories" << std::endl;

    return 0;
}
