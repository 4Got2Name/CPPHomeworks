#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

enum FormOfEducation{
	DAY_TIME = 1,
	NIGHT_TIME = 2
};

struct Student{
	FormOfEducation form;
	string name;
	string gradebook;
	int course;
	float grade;
};

string getFormName(FormOfEducation form) {
    return (form == DAY_TIME) ? "Денна" : "Заочна";
}

// Завдання 1: Функція для виведення інформації про студента
void displayStudent(const Student& student) {
    cout << "Ім'я: " << student.name << endl;
    cout << "Номер залікової книжки: " << student.gradebook << endl;
    cout << "Форма навчання: " << getFormName(student.form) << endl;
    cout << "Курс: " << student.course << endl;
    cout << "Середній бал: " << student.grade << endl;
}

// Завдання 2: Функція для заповнення структури від користувача
Student inputStudent() {
    Student s;
    
    cout << "Введення даних студента: " << endl;
    
    cout << "Ім'я студента: ";
    cin.ignore();
    getline(cin, s.name);
    
    cout << "Номер залікової книжки: ";
    getline(cin, s.gradebook);
    
    cout << "Форма навчання (1 - Денна, 2 - Заочна): ";
    int form;
    cin >> form;
    s.form = (form == 1) ? DAY_TIME : NIGHT_TIME;
    
    cout << "Курс (1-4): ";
    cin >> s.course;
    
    cout << "Середній бал: ";
    cin >> s.grade;
    
    return s;
}

// Функція для виведення всіх студентів з таблиці
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nНемає студентів для відображення!\n" << endl;
        return;
    }
    
    cout << "\n";
    cout << left << setw(20) << "Ім'я" 
         << setw(18) << "Залік. книжка" 
         << setw(12) << "Форма" 
         << setw(8) << "Курс" 
         << setw(10) << "Бал" << endl;
    cout << string(68, '-') << endl;
    
    for (const auto& student : students) {
        cout << left << setw(20) << student.name 
             << setw(18) << student.gradebook 
             << setw(12) << getFormName(student.form)
             << setw(8) << student.course
             << student.grade << endl;
    }
    cout << "\n";
}

// Завдання 3: Функції для сортування та фільтрації

// Функція для сортування за номером залікової книжки
void sortByGradebook(vector<Student>& students) {
    sort(students.begin(), students.end(), 
         (const Student& a, const Student& b) {
             return a.gradebook < b.gradebook;
         });
    cout << "\nСортування за номером залікової книжки завершено!" << endl;
}

// Функція для сортування за середнім балом (спадаючи)
void sortByGrade(vector<Student>& students) {
    sort(students.begin(), students.end(), 
         (const Student& a, const Student& b) {
             return a.grade > b.grade;
         });
    cout << "\nСортування за середнім балом завершено!" << endl;
}

// Функція для фільтрації за курсом
vector<Student> filterByCourse(const vector<Student>& students, int course) {
    vector<Student> filtered;
    copy_if(students.begin(), students.end(), back_inserter(filtered),
            [course](const Student& s) { return s.course == course; });
    return filtered;
}

// Функція для фільтрації за формою навчання
vector<Student> filterByForm(const vector<Student>& students, FormOfEducation form) {
    vector<Student> filtered;
    copy_if(students.begin(), students.end(), back_inserter(filtered),
            [form](const Student& s) { return s.form == form; });
    return filtered;
}

// Функція для фільтрації за мінімальним балом
vector<Student> filterByMinGrade(const vector<Student>& students, double minGrade) {
    vector<Student> filtered;
    copy_if(students.begin(), students.end(), back_inserter(filtered),
            [minGrade](const Student& s) { return s.grade >= minGrade; });
    return filtered;
}

// Головне меню
void showMenu() {
    cout << "\n===== ОБЛІК СТУДЕНТІВ В УНІВЕРСИТЕТІ =====" << endl;
    cout << "1. Додати студента" << endl;
    cout << "2. Вивести всіх студентів" << endl;
    cout << "3. Вивести інформацію про студента" << endl;
    cout << "4. Сортування студентів" << endl;
    cout << "5. Фільтрація студентів" << endl;
    cout << "0. Вихід" << endl;
    cout << "==========================================" << endl;
    cout << "Оберіть опцію: ";
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    vector<Student> students;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                students.push_back(inputStudent());
                cout << "\nСтудента успішно додано!" << endl;
                break;
            }
            
            case 2: {
                displayAllStudents(students);
                break;
            }
            
            case 3: {
                if (students.empty()) {
                    cout << "\nНемає студентів!" << endl;
                    break;
                }
                cout << "\nВиберіть номер студента (1-" << students.size() << "): ";
                int idx;
                cin >> idx;
                if (idx > 0 && idx <= students.size()) {
                    displayStudent(students[idx - 1]);
                } else {
                    cout << "\nНекорректний номер!" << endl;
                }
                break;
            }
            
            case 4: {
                if (students.empty()) {
                    cout << "\nНемає студентів для сортування!" << endl;
                    break;
                }
                cout << "\nОберіть критерій сортування:" << endl;
                cout << "1. За номером залікової книжки" << endl;
                cout << "2. За середнім балом (від більшого)" << endl;
                cout << "Виберіть: ";
                int sortChoice;
                cin >> sortChoice;
                
                vector<Student> sortedStudents = students;
                if (sortChoice == 1) {
                    sortByGradebook(sortedStudents);
                } else if (sortChoice == 2) {
                    sortByGrade(sortedStudents);
                } else {
                    cout << "\nНекорректний вибір!" << endl;
                    break;
                }
                
                displayAllStudents(sortedStudents);
                break;
            }
            
            case 5: {
                if (students.empty()) {
                    cout << "\nНемає студентів для фільтрації!" << endl;
                    break;
                }
                cout << "\nОберіть критерій фільтрації:" << endl;
                cout << "1. За курсом" << endl;
                cout << "2. За формою навчання" << endl;
                cout << "3. За мінімальним балом" << endl;
                cout << "Виберіть: ";
                int filterChoice;
                cin >> filterChoice;
                
                vector<Student> filtered;
                if (filterChoice == 1) {
                    cout << "Введіть курс (1-4): ";
                    int course;
                    cin >> course;
                    filtered = filterByCourse(students, course);
                } else if (filterChoice == 2) {
                    cout << "Форма навчання (1 - Денна, 2 - Заочна): ";
                    int form;
                    cin >> form;
                    filtered = filterByForm(students, (form == 1) ? DAY_TIME : NIGHT_TIME);
                } else if (filterChoice == 3) {
                    cout << "Введіть мінімальний бал: ";
                    double minGrade;
                    cin >> minGrade;
                    filtered = filterByMinGrade(students, minGrade);
                } else {
                    cout << "\nНекорректний вибір!" << endl;
                    break;
                }
                
                cout << "\nРезультати фільтрації: " << filtered.size() << " студент(ів)" << endl;
                displayAllStudents(filtered);
                break;
            }
            
            case 0: {
                cout << "\nДо побачення!" << endl;
                break;
            }
            
            default:
                cout << "\nНекорректний вибір! Спробуйте ще раз." << endl;
        }
        
    } while (choice != 0);
    
    return 0;

}
