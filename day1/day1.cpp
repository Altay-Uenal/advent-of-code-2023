#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc < 2) return 1;

    std::ifstream file(argv[1]);
    std::string line;
    char first = 0;
    char last;
    int sum = 0;
    std::string num = "";

    if (!file.is_open()) return 1;

    while (std::getline(file, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                if (first == 0) first = line[i];
                last = line[i];
            }
        }
        sum += stoi(num+first+last);
        first = 0;
    }

    std::cout << sum << std::endl;
    return 0;
}
