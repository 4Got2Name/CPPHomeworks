#include <iostream>

// Створюємо функцію додавання десяткових дробів

double add(double a, double b){
	return a+b;
}

// Створюємо функцію віднімання десяткових дробів

double substract(double a, double b){
	return a-b;
}

// Створюємо функцію множення десяткових дробів

double multiply(double a, double b){
	return a*b;
}

// Створюємо функцію ділення десяткових дробів, з перевіркою чи дільник не ділиться на 0

double divide(double a, double b){
	return a/b;
}

// Створюємо функцію, яка буде повертати числа, який записав користувач для обчислення

double getUserNumber(const char* prompt){
	double num;
	std::cout << prompt;
	std::cin >> num;
	return num;
}

// Створюємо функцію, яка буде ввиводити на екран додавання

void DisplayAddition(double num1, double num2){
	double result = add(num1,num2);
	std::cout << "Результат: " << num1 << " + " << num2 << " = " << result << std::endl;
}

// Створюємо функцію, яка буде ввиводити на екран віднімання

void DisplaySubstraction(double num1, double num2){
	double result = substract(num1,num2);
	std::cout << "Результат: " << num1 << " - " << num2 << " = " << result << std::endl;
}

// Створюємо функцію, яка буде ввиводити на екран множення

void DisplayMultiplication(double num1, double num2){
	double result = multiply(num1,num2);
	std::cout << "Результат: " << num1 << " * " << num2 << " = " << result << std::endl;
}

// Створюємо функцію, яка буде ввиводити на екран ділення, з попередженням коли дільник дорівнює 0

void DisplayDivision(double num1, double num2){
	if (num2 == 0){
		std::cout << "На нуль ділити не можна" << std::endl;
	} else {
	double result = divide(num1,num2);
	std::cout << "Результат: " << num1 << " / " << num2 << " = " << result << std::endl;
	}
}

// Створюємо функцію для виконання обчислень з використанням форми case

void displayCalculation(double num1, double num2, char op){
	switch (op){
		case '+':
			DisplayAddition(num1,num2);
			break;
		case '-':
			DisplaySubstraction(num1,num2);
			break;
		case '*':
			DisplayMultiplication(num1,num2);
			break;
		case '/':
			DisplayDivision(num1,num2);
			break;
		default:
			std::cout << "Ви ввели невідому операцію" << std::endl;
			break;
	}
}
int main(){
	char op;
	double num1,num2;

while(true){ 																	// Нескінчений цикл програми
	std::cout << "Оберіть операцію (+, -, *, / або 0 для виходу): ";
	std::cin >> op;

	if (op == '0'){																// Перевірка на вихід
		std::cout << "Вихід з програми... " << std::endl;
		break;
	}

	num1 = getUserNumber("Введіть перше число: ");
	num2 = getUserNumber("Введіть друге число: ");
	
	displayCalculation(num1,num2, op);
}
}




