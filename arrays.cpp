#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Константа для довжини масиву
const int ARRAY_LENGTH = 10;

// Функція виведення головного меню
void displayMenu() {
    cout << "Оберіть операцію:" << endl;
    cout << "1) Ввести значення елементів масиву" << endl;
    cout << "2) Вивести значення елементів масиву" << endl;
    cout << "3) Обчислення мінімального значення" << endl;
    cout << "4) Обчислення максимального значення" << endl;
    cout << "5) Обчислення середнього арифметичного значення" << endl;
    cout << "6) Відсортувати масив" << endl;
    cout << "7) Вийти" << endl;
}

// Функція для очищення буфера введення
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функція для введення значень масиву
void inputArrayValues(int arr[], bool& isInitialized) {
    cout << "Введіть " << ARRAY_LENGTH << " цілих чисел:" << endl;
    
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << "Елемент [" << i << "]: ";
        cin >> arr[i];
        
        // Перевірка коректності введення
        while (cin.fail()) {
            clearInputBuffer();
            cout << "[Помилка] Введіть ціле число!" << endl;
            cout << "Елемент [" << i << "]: ";
            cin >> arr[i];
        }
    }
    
    isInitialized = true;
    cout << "\n[Успішно] Масив ініціалізовано!" << endl;
}

// Функція для виведення значень масиву
void printArrayValues(const int arr[], bool& isInitialized) {
    if (!isInitialized) {
        cout << "[Помилка] Масив не ініціалізовано! Спочатку введіть значення (опція 1)." << endl;
        return;
    }
    
    cout << "Значення елементів масиву:" << endl;
    cout << "[";
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << arr[i];
        if (i < ARRAY_LENGTH - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Функція для знаходження мінімального значення
int findMinValue(const int arr[], bool& isInitialized) {
    if (!isInitialized) {
        cout << "[Помилка] Масив не ініціалізовано! Спочатку введіть значення (опція 1)." << endl;
        return 0;
    }
    
    int minValue = arr[0];
    for (int i = 1; i < ARRAY_LENGTH; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    
    return minValue;
}

// Функція для знаходження максимального значення
int findMaxValue(const int arr[], bool& isInitialized) {
    if (!isInitialized) {
        cout << "[Помилка] Масив не ініціалізовано! Спочатку введіть значення (опція 1)." << endl;
        return 0;
    }
    
    int maxValue = arr[0];
    for (int i = 1; i < ARRAY_LENGTH; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    
    return maxValue;
}

// Функція для обчислення середнього арифметичного
double calculateAverage(const int arr[], bool& isInitialized) {
    if (!isInitialized) {
        cout << "[Помилка] Масив не ініціалізовано! Спочатку введіть значення (опція 1)." << endl;
        return 0.0;
    }
    
    long long sum = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        sum += arr[i];
    }
    
    return static_cast<double>(sum) / ARRAY_LENGTH;
}

void sortArray(int arr[], bool& isInitialized) {
    if (!isInitialized) {
        cout << "[Помилка] Масив не ініціалізовано! Спочатку введіть значення (опція 1)." << endl;
        return;
    }
    
    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        for (int j = 0; j < ARRAY_LENGTH - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    cout << "[Успішно] Масив відсортовано за зростанням!" << endl;
    printArrayValues(arr, isInitialized);
}

int main() {
    int array[ARRAY_LENGTH];
    bool isInitialized = false;
    int choice;

    cout << "Програма для роботи з масивом" << endl;
    cout << "Розмір масиву: " << ARRAY_LENGTH << " елементів" << endl << endl;

    while (true) {
        displayMenu();
        cout << "Ваш вибір: ";
        cin >> choice;

        // Перевірка коректності введення
        if (cin.fail()) {
            clearInputBuffer();
            cout << "\n[Помилка] Некоректне введення! Введіть число від 1 до 7.\n" << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
            case 1:
                inputArrayValues(array, isInitialized);
                break;

            case 2:
                printArrayValues(array, isInitialized);
                break;

            case 3:
                if (isInitialized) {
                    int minValue = findMinValue(array, isInitialized);
                    cout << "Мінімальне значення: " << minValue << endl;
                }
                break;

            case 4:
                if (isInitialized) {
                    int maxValue = findMaxValue(array, isInitialized);
                    cout << "Максимальне значення: " << maxValue << endl;
                }
                break;

            case 5:
                if (isInitialized) {
                    double average = calculateAverage(array, isInitialized);
                    cout << "Середнє арифметичне значення: " << average << endl;
                }
                break;

            case 6:
                sortArray(array, isInitialized);
                break;

            case 7:
                cout << "Завершення роботи програми. До побачення!" << endl;
                return 0;

            default:
                cout << "[Помилка] Невірний вибір! Оберіть опцію від 1 до 7." << endl;
        }

        cout << endl;
    }

    return 0;
}
