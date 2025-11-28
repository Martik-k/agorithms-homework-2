#include <iostream>
#include <string>
#include <unordered_set>

int length_min_row() {
    std::string line;
    getline(std::cin, line);
    std::unordered_set<char> letters;

    for (char& c : line) {
        if (c != ' ') letters.insert(c);
    }
    return static_cast<int>(letters.size());
}

int main() {
    std::cout << length_min_row() << std::endl;
    return 0;
}