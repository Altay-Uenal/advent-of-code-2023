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
            } else {
                switch (line[i]) {
                    case 'o':
                        if (line.substr(i, 3) == "one") {
                            if (first == 0) first = '1';
                            last = '1';
                            i+=1;
                        }
                        break;

                    case 't':
                        if (line.substr(i, 3) == "two") {
                            if (first == 0) first = '2';
                            last = '2';
                            i+=1;
                        } else if (line.substr(i, 5) == "three") {
                            if (first == 0) first = '3';
                            last = '3';
                            i+=3;
                        }
                        break;

                    case 'f':
                        if (line.substr(i, 4) == "four") {
                            if (first == 0) first = '4';
                            last = '4';
                            i+=2;
                        } else if (line.substr(i, 4) == "five") {
                            if (first == 0) first = '5';
                            last = '5';
                            i+=2;
                        }
                        break;

                    case 's':
                        if (line.substr(i, 3) == "six") {
                            if (first == 0) first = '6';
                            last = '6';
                            i+=1;
                        } else if (line.substr(i, 5) == "seven") {
                            if (first == 0) first = '7';
                            last = '7';
                            i+=3;
                        }
                        break;

                    case 'e':
                        if (line.substr(i, 5) == "eight") {
                            if (first == 0) first = '8';
                            last = '8';
                            i+=3;
                        }
                        break;

                    case 'n':
                        if (line.substr(i, 4) == "nine") {
                            if (first == 0) first = '9';
                            last = '9';
                            i+=2;
                        }
                        break;
                    default: //do nothing
                        break;
                }
            }
        }
        sum += stoi(num+first+last);
        first = 0;
    }

    std::cout << sum << std::endl;
    return 0;
}
