#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "simple-db.cpp"

using namespace std;

enum FormOfEducation{
	DAY_TIME = 1,
	NIGHT_TIME = 2
};

struct Student{
	FormOfEducation form;
	string name;
	int gradebook;
	int course;
	float grade;
	
	void serialize(ofstream& outFile) const {
		SimpleDB::writeElement(outFile, static_cast<int>(form));
		SimpleDB::writeElement(outFile, name);
		SimpleDB::writeElement(outFile, gradebook);
		SimpleDB::writeElement(outFile, course);
		SimpleDB::writeElement(outFile, grade);
	}
	
	void deserialize(ifstream& inFile) {
		int formInt;
		SimpleDB::readElement(inFile, formInt);
		form = static_cast<FormOfEducation>(formInt);
		SimpleDB::readElement(inFile, name);
		SimpleDB::readElement(inFile, gradebook);
		SimpleDB::readElement(inFile, course);
		SimpleDB::readElement(inFile, grade);
	}
};

string getFormName(FormOfEducation form) {
    return (form == DAY_TIME) ? "Денна" : "Заочна";
}

void displayStudent(const Student& student) {
    cout << "Ім'я: " << student.name << endl;
    cout << "Номер залікової книжки: " << student.gradebook << endl;
    cout << "Форма навчання: " << getFormName(student.form) << endl;
    cout << "Курс: " << student.course << endl;
    cout << "Середній бал: " << fixed << setprecision(2) << student.grade << endl;
}

Student inputStudent() {
    Student s;
    
    cout << "Введення даних студента: " << endl;
    
    cout << "Ім'я студента: ";
    cin.ignore();
    getline(cin, s.name);
    
    cout << "Номер залікової книжки: ";
    cin >> s.gradebook;
    
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

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nНемає студентів для відображення!\n" << endl;
        return;
    }
    
    cout << "\n";
    cout << left << setw(35) << "Ім'я" 
         << setw(10) << "№ Заліку" 
         << setw(15) << "Форма" 
         << right << setw(8) << "Курс" 
         << setw(10) << "Бал" << endl;
    cout << string(78, '-') << endl;
    
    for (const auto& student : students) {
        cout << left << setw(35) << student.name 
             << setw(10) << student.gradebook 
             << setw(15) << getFormName(student.form)
             << right << setw(8) << student.course
             << setw(10) << fixed << setprecision(2) << student.grade << endl;
    }
    cout << "\n";
}

void sortByGradebook(vector<Student>& students) {
    sort(students.begin(), students.end(), 
         [](const Student& a, const Student& b) {
             return a.gradebook < b.gradebook;
         });
    cout << "\nСортування за номером залікової книжки завершено!" << endl;
}

void sortByGrade(vector<Student>& students) {
    sort(students.begin(), students.end(), 
         [](const Student& a, const Student& b) {
             return a.grade > b.grade;
         });
    cout << "\nСортування за середнім балом завершено!" << endl;
}

vector<Student> filterByCourse(const vector<Student>& students, int course) {
    vector<Student> filtered;
    copy_if(students.begin(), students.end(), back_inserter(filtered),
            [course](const Student& s) { return s.course == course; });
    return filtered;
}

vector<Student> filterByForm(const vector<Student>& students, FormOfEducation form) {
    vector<Student> filtered;
    copy_if(students.begin(), students.end(), back_inserter(filtered),
            [form](const Student& s) { return s.form == form; });
    return filtered;
}

vector<Student> filterByMinGrade(const vector<Student>& students, double minGrade) {
    vector<Student> filtered;
    copy_if(students.begin(), students.end(), back_inserter(filtered),
            [minGrade](const Student& s) { return s.grade >= minGrade; });
    return filtered;
}
vector<Student> getInitialData() {
    vector<Student> students;
    
    students.push_back({DAY_TIME, "Борух Маркіян", 1, 2, 9});
    students.push_back({DAY_TIME, "Бурий Святослав", 2, 2, 2});
    students.push_back({NIGHT_TIME, "Бучківська Катерина", 3, 2, 10});
    students.push_back({DAY_TIME, "Войтко Андрій", 4, 2, 6});
    students.push_back({DAY_TIME, "Галкін Андрій-Володимир", 5, 2, 5});
    students.push_back({NIGHT_TIME, "Заяць Діана", 6, 2, 10});
    students.push_back({DAY_TIME, "Ілевич Богдан", 7, 2, 7});
    students.push_back({DAY_TIME, "Кишинський Михайло", 8, 2, 3});
    students.push_back({DAY_TIME, "Ковальчук Олег", 9, 2, 8});
    students.push_back({NIGHT_TIME, "Корольов Владислав", 10, 2, 8});
    students.push_back({DAY_TIME, "Коротких Вікторія", 11, 2, 9});
    students.push_back({DAY_TIME, "Космина Олег", 12, 2, 0});
    students.push_back({DAY_TIME, "Курило Владислав", 13, 2, 3});
    students.push_back({NIGHT_TIME, "Левус Анна", 14, 2, 11});
    students.push_back({DAY_TIME, "Луцишин Данило", 15, 2, 7});
    students.push_back({DAY_TIME, "Мельник Назарій", 16, 2, 6});
    students.push_back({DAY_TIME, "Мотрук Матвій", 17, 2, 6});
    students.push_back({NIGHT_TIME, "Мукомел Єгор", 18, 2, 5});
    students.push_back({DAY_TIME, "Наконечний Остап", 19, 2, 8});
    students.push_back({DAY_TIME, "Ножкін Максим", 20, 2, 9});
    students.push_back({DAY_TIME, "Павлишин Андріана", 21, 2, 10});
    students.push_back({NIGHT_TIME, "Поніжай Юлія", 22, 2, 10});
    students.push_back({DAY_TIME, "Рахманов Олександр", 23, 2, 7});
    students.push_back({DAY_TIME, "Рій Ірина", 24, 2, 9});
    students.push_back({DAY_TIME, "Саучик Артур", 25, 2, 6});
    students.push_back({NIGHT_TIME, "Станько Юрій", 26, 2, 5});
    students.push_back({DAY_TIME, "Тераз Максим", 27, 2, 3});
    students.push_back({DAY_TIME, "Труш Ростислав", 28, 2, 5});
    students.push_back({DAY_TIME, "Ухач Микола", 29, 2, 4});
    students.push_back({NIGHT_TIME, "Царюк Євгеній", 30, 2, 7});
    students.push_back({DAY_TIME, "Швед Остап", 31, 2, 8});
    students.push_back({DAY_TIME, "Шмуш Кирило", 32, 2, 7});
    
    return students;
}

void saveToDatabase(const vector<Student>& students) {
    try {
        SimpleDB::serialize(students);
        cout << "\nДані успішно збережено в базу даних!" << endl;
    } catch (const exception& e) {
        cout << "\nПомилка збереження: " << e.what() << endl;
    }
}

vector<Student> loadFromDatabase() {
    try {
        vector<Student> students = SimpleDB::load<Student>();
        cout << "\nДані успішно завантажено з бази даних!" << endl;
        return students;
    } catch (const exception& e) {
        cout << "\nПомилка завантаження: " << e.what() << endl;
        return vector<Student>();
    }
}

void showMenu() {
    cout << "\nОБЛІК СТУДЕНТІВ групи ІП-22" << endl;
    cout << "1. Додати студента" << endl;
    cout << "2. Вивести всіх студентів" << endl;
    cout << "3. Вивести інформацію про студента" << endl;
    cout << "4. Сортування студентів" << endl;
    cout << "5. Фільтрація студентів" << endl;
    cout << "6. Зберегти дані в БД" << endl;
    cout << "7. Завантажити дані з БД" << endl;
    cout << "8. Ініціалізувати тестовими даними" << endl;
    cout << "0. Вихід" << endl;
    cout << "==========================================" << endl;
    cout << "Оберіть опцію: ";
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    vector<Student> students = SimpleDB::load<Student>();
    
    if (students.empty()) {
        cout << "База даних порожня. Завантажуємо тестові дані..." << endl;
        students = getInitialData();
        SimpleDB::serialize(students);
        cout << "Тестові дані завантажено та збережено!" << endl;
    } else {
        cout << "Завантажено " << students.size() << " студент(ів) з бази даних." << endl;
    }
    
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
                if (idx > 0 && idx <= static_cast<int>(students.size())) {
                    cout << "\n";
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
            
            case 6: {
                saveToDatabase(students);
                break;
            }
            
            case 7: {
                students = loadFromDatabase();
                if (!students.empty()) {
                    cout << "Завантажено " << students.size() << " студент(ів)." << endl;
                }
                break;
            }
            
            case 8: {
                cout << "\nУвага! Це замінить поточні дані тестовими." << endl;
                cout << "Продовжити? (1 - Так, 0 - Ні): ";
                int confirm;
                cin >> confirm;
                if (confirm == 1) {
                    students = getInitialData();
                    cout << "\nТестові дані завантажено (" << students.size() << " студентів)!" << endl;
                }
                break;
            }
            
            case 0: {
                cout << "\nЗберегти зміни перед виходом? (1 - Так, 0 - Ні): ";
                int save;
                cin >> save;
                if (save == 1) {
                    saveToDatabase(students);
                }
                cout << "\nДо побачення!" << endl;
                break;
            }
            
            default:
                cout << "\nНекорректний вибір! Спробуйте ще раз." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
