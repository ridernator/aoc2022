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

    for (size_t index = 0; index < lines.size(); index += 3) {
        std::string elf1 = lines[index];
        std::string elf2 = lines[index + 1];
        std::string elf3 = lines[index + 2];

        std::sort(elf1.begin(), elf1.end());
        std::sort(elf2.begin(), elf2.end());
        std::sort(elf3.begin(), elf3.end());
     
        std::string intersection12;
        std::string intersection123;
     
        std::set_intersection(elf1.begin(), elf1.end(),
                              elf2.begin(), elf2.end(),
                              std::back_inserter(intersection12));
     
        std::set_intersection(intersection12.begin(), intersection12.end(),
                              elf3.begin(), elf3.end(),
                              std::back_inserter(intersection123));

        if (!intersection123.empty()) {
            total += letterToNumber(intersection123[0]);
        }
    }

    std::cout << "Sum is " << total << std::endl;

    return 0;
}
