#include <iostream>
int getValueByInput() {
	int input{};
	std::cout << "Enter an integer: ";
	std::cin >> input;
	return input;
}
int addition(int x,int y) {
	std::cout << "The addition is: " << x << " + " << y << " = " << x + y << '\n';
	return x, y;
}
int subtraction(int x, int y) {
	std::cout << "The subtraction is: " << x << " - " << y << " = " << x - y << '\n';
	return x, y;
}
int multiplication(int x, int y) {
	std::cout << "The multiplication is: " << x << " * " << y << " = " << x * y << '\n';
	return x, y;
}
int division(int x, int y) {
	std::cout << "The division is: " << x << " / " << y << " = " << x / y << '\n';
	return x, y;
}
int main() {
	int input_x{ getValueByInput() };
	int input_y{ getValueByInput() };
	addition(input_x, input_y);
	subtraction(input_x, input_y);
	multiplication(input_x, input_y);
	division(input_x, input_y);
	return 0;
}
/*void test() {
	std::cout << "Enter an integer: ";
	int n{};
	std::cin >> n;

	std::cout << "Double that number is:" << n*2 << '\n'; 
	return n;
}*/