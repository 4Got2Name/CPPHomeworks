#include <iostream>
#include <string>
#include <limits>
#include <sstream>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getBoolValue() {
    std::string input;
    
    while (true) {
        std::cout << "Введіть логічне значення (0 - False або 1 - True): ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Помилка: Порожній ввід не допускається!" << std::endl;
            continue;
        }
        
        if (input.length() != 1) {
            std::cout << "Помилка: Введіть тільки 0 або 1!" << std::endl;
            continue;
        }
        
        if (input[0] == '0') {
            return false;
        } else if (input[0] == '1') {
            return true;
        } else {
            std::cout << "Помилка: Допускаються тільки значення 0 або 1!" << std::endl;
        }
    }
}

char getCharValue() {
    std::string input;
    
    while (true) {
        std::cout << "Введіть символ (a-f): ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Помилка: Порожній ввід не допускається!" << std::endl;
            continue;
        }
        
        if (input.length() != 1) {
            std::cout << "Помилка: Введіть тільки один символ!" << std::endl;
            continue;
        }
        
        char ch = input[0];
        
        if (ch >= 'a' && ch <= 'f') {
            return ch;
        } else {
            std::cout << "Помилка: Допускаються тільки символи a, b, c, d, e, f!" << std::endl;
        }
    }
}

float getFloatValue() {
    std::string input;
    
    while (true) {
        std::cout << "Введіть дробове число (через крапку): ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Помилка: Порожній ввід не допускається!" << std::endl;
            continue;
        }
        
        std::stringstream ss(input);
        float value;
        char remaining;
    
        if (ss >> value && !(ss >> remaining)) {
            return value;
        } else {
            std::cout << "Помилка: Введіть коректне дробове число!" << std::endl;
        }
    }
}

short getShortValue() {
    std::string input;
    
    while (true) {
        std::cout << "Введіть ціле число (-32767 до 32767): ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Помилка: Порожній ввід не допускається!" << std::endl;
            continue;
        }
        
        std::stringstream ss(input);
        int value;
        char remaining;
        
        if (ss >> value && !(ss >> remaining)) {
            if (value >= -32767 && value <= 32767) {
                return static_cast<short>(value);
            } else {
                std::cout << "Помилка: Число поза допустимим діапазоном (-32767 до 32767)!" << std::endl;
            }
        } else {
            std::cout << "Помилка: Введіть коректне ціле число!" << std::endl;
        }
    }
}

int main() {
    std::cout << "Вас вітає програма валідації типів даних" << '\n' << std::endl;
    
    bool boolValue = getBoolValue();
    std::cout << "Успішно отримано boolean значення: " << (boolValue ? "true" : "false") << '\n' << std::endl;
    
    char charValue = getCharValue();
    std::cout << "Успішно отримано char значення: " << charValue << '\n' << std::endl;
    
    float floatValue = getFloatValue();
    std::cout << "Успішно отримано float значення: " << floatValue << '\n' << std::endl;
    
    short shortValue = getShortValue();
    std::cout << "Успішно отримано short значення: " << shortValue << '\n' << std::endl; // між '\n' та std::endl різниці нема
    
    return 0;
}

