#include <iostream>
#include <string>

class bad_length {};

int function(std::string str, int forbidden_length) {
    int len = str.length();
    if (len == forbidden_length) {
        throw bad_length();
    }
    return len;
}

int main() {
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    std::string str;
    while (true) {
        std::cout << "Введите слово: ";
        std::cin>>str;
        try {
            int len = function(str, forbidden_length);
            std::cout << "Длина слова \"" << str << "\" равна " << len << std::endl;
        }
        catch (const bad_length&) {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            break;
        }
    }
}
