#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14159265359;

class Circle {
private:
    double radius;      
    double area;       
    double length;
  

    void updateCalculations() {
        area = pi * radius * radius;
        length = 2 * pi * radius;
    }
    
public:
    Circle(){
        radius = 1.0;
        updateCalculations();
        cout << "Створено об'єкт Circle за замовчуванням" << endl;
    }
    
    Circle(double r){
        radius = r;
        updateCalculations();
        cout << "Створено об'єкт Circle з радіусом " << r << endl;
    }
    
    ~Circle() {
        cout << "Знищено об'єкт Circle з радіусом " << radius << endl;
    }

    double getRadius() const {
        return radius;
    }
    
    double getArea() const {
        return area;
    }
    
    double getlength() const {
        return length;
    }
    
    Circle& setRadius(double r) {
        if (r > 0) {
            radius = r;
            updateCalculations();
        } else {
            cout << "Помилка: радіус повинен бути додатнім!" << endl;
        }
        return *this;
    }
    
    Circle& setArea(double a) {
        if (a > 0) {
            area = a;
            radius = sqrt(a / pi);
            length = 2 * pi * radius;
        } else {
            cout << "Помилка: площа повинна бути додатною!" << endl;
        }
        return *this;
    }
    
    Circle& setlength(double l) {
        if (l > 0) {
            length = l;
            radius = l / (2 * pi);
            area = pi * radius * radius;
        } else {
            cout << "Помилка: довжина повинна бути додатною!" << endl;
        }
        return *this;
    }
    
    void print() const {
        cout << "Інформація про коло:" << endl;
        cout << "  Радіус:       " << radius << endl;
        cout << "  Площа:        " << area << endl;
        cout << "  Довжина кола: " << length << endl;
    }
};

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    
    cout << "1. Створення кола за замовчуванням:" << endl;
    Circle circle1;
    circle1.print();
    
    cout << "\n2. Створення кола з радіусом 5:" << endl;
    Circle circle2(5.0);
    circle2.print();
    
    cout << "\n3. Створення кола за замовчуванням та змінюємо радіус на 3:" << endl;
    Circle circle3;
    circle3.setRadius(3.0).print();
    
    cout << "\n4. Створення кола за радіусом на 2 та змінюємо радіус на 7, потім на 10:" << endl;
    Circle circle4(2.0);
    circle4.print();
    cout << "\nОсь і початкове значення кола, тепер подивимось на наступне" << endl;
    circle4.setRadius(7.0).setRadius(10.0).print();
    
    cout << "\n5. Встановлення кола через площу (площа = 50):" << endl;
    Circle circle5;
    circle5.setArea(50.0).print();
    
    cout << "\n6. Встановлення кола через довжину (довжина = 30):" << endl;
    Circle circle6;
    circle6.setlength(30.0).print();
    
    cout << "\n7. Використання геттерів для circle2:" << endl;
    cout << "Радіус: " << circle2.getRadius() << endl;
    cout << "Площа: " << circle2.getArea() << endl;
    cout << "Довжина: " << circle2.getlength() << endl;
    
    return 0;
}