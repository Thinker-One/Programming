#include <iostream>
#include <array>

int main() {
    
    size_t strLen = 0, optionFre = 0;
    std::cin >> strLen >> optionFre;
    std::array<char, strLen> str;

    for (int i=0; i < strLen; ++i) {
        std::cin >> str[i];
    }
}
