#include <iostream>
#include <random>
#include <limits>

using namespace std;

int getRandomNumber(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

bool isValidInput(int& number) {
    if (cin >> number) {
        return true;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}

void playGame() {
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    const int MAX_ATTEMPTS = 10;
    
    int secretNumber = getRandomNumber(MIN_NUMBER, MAX_NUMBER);
    int attempts = 0;
    int guess;
    bool won = false;
    
    cout << "Я загадав число від " << MIN_NUMBER << " до " << MAX_NUMBER << endl;
    cout << "У вас є " << MAX_ATTEMPTS << " спроб, щоб вгадати його." << endl;
    
    while (attempts < MAX_ATTEMPTS && !won) {
        cout << "\nСпроба " << (attempts + 1) << " з " << MAX_ATTEMPTS << endl;
        cout << "Введіть ваше число: ";
        
        if (!isValidInput(guess)) {
            cout << "Помилка! Введіть ціле число." << endl;
            continue;
        }
        
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            cout << "Число повинно бути в діапазоні від " << MIN_NUMBER 
                 << " до " << MAX_NUMBER << "!" << endl;
            continue;
        }
        
        attempts++;
        
        if (guess == secretNumber) {
            won = true;
            cout << "\nВітаю! Ви вгадали число " << secretNumber 
                 << " за " << attempts << " спроб!" << endl;
        } else if (guess < secretNumber) {
            cout << "Ваше число менше загаданого!" << endl;
        } else {
            cout << "Ваше число більше загаданого!" << endl;
        }
    }
    
    if (!won) {
        cout << "\nВи використали всі спроби! Загадане число було: " 
             << secretNumber << endl;
    }
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    char playAgain;
    
    cout << "Ласкаво просимо до гри 'Вгадай число'!" << endl;
    
    do {
        playGame();
        
        cout << "\nБажаєте зіграти ще раз? (1 - так / 2 - ні): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (playAgain == '1');
    
    cout << "\nДякуємо за гру!" << endl;
    
    return 0;
}