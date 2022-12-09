#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
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

void initStacks(std::map<uint32_t, std::stack<char>>& stacks) {
//     [G] [R]                 [P]    
//     [H] [W]     [T] [P]     [H]    
//     [F] [T] [P] [B] [D]     [N]    
// [L] [T] [M] [Q] [L] [C]     [Z]    
// [C] [C] [N] [V] [S] [H]     [V] [G]
// [G] [L] [F] [D] [M] [V] [T] [J] [H]
// [M] [D] [J] [F] [F] [N] [C] [S] [F]
// [Q] [R] [V] [J] [N] [R] [H] [G] [Z]
//  1   2   3   4   5   6   7   8   9 

    stacks[1].push('Q');
    stacks[1].push('M');
    stacks[1].push('G');
    stacks[1].push('C');
    stacks[1].push('L');

    stacks[2].push('R');
    stacks[2].push('D');
    stacks[2].push('L');
    stacks[2].push('C');
    stacks[2].push('T');
    stacks[2].push('F');
    stacks[2].push('H');
    stacks[2].push('G');

    stacks[3].push('V');
    stacks[3].push('J');
    stacks[3].push('F');
    stacks[3].push('N');
    stacks[3].push('M');
    stacks[3].push('T');
    stacks[3].push('W');
    stacks[3].push('R');

    stacks[4].push('J');
    stacks[4].push('F');
    stacks[4].push('D');
    stacks[4].push('V');
    stacks[4].push('Q');
    stacks[4].push('P');

    stacks[5].push('N');
    stacks[5].push('F');
    stacks[5].push('M');
    stacks[5].push('S');
    stacks[5].push('L');
    stacks[5].push('B');
    stacks[5].push('T');

    stacks[6].push('R');
    stacks[6].push('N');
    stacks[6].push('V');
    stacks[6].push('H');
    stacks[6].push('C');
    stacks[6].push('D');
    stacks[6].push('P');

    stacks[7].push('H');
    stacks[7].push('C');
    stacks[7].push('T');

    stacks[8].push('G');
    stacks[8].push('S');
    stacks[8].push('J');
    stacks[8].push('V');
    stacks[8].push('Z');
    stacks[8].push('N');
    stacks[8].push('H');
    stacks[8].push('P');

    stacks[9].push('Z');
    stacks[9].push('F');
    stacks[9].push('H');
    stacks[9].push('G');
}

int main() {
    auto lines = readFileToVector();

    std::map<uint32_t, std::stack<char>> stacks;
    initStacks(stacks);

    uint32_t count;
    uint32_t from;
    uint32_t to;

    for (const auto& line : lines) {
        sscanf(line.c_str(), "move %u from %u to %u", &count, &from, &to);

        for (uint32_t index = 0; index < count; ++index) {
            stacks[to].push(stacks[from].top());
            stacks[from].pop();
        }
    }

    for (uint32_t index = 1; index < 10; ++index) {
        std::cout << stacks[index].top();
    }

    std::cout << std::endl;

    return 0;
}
