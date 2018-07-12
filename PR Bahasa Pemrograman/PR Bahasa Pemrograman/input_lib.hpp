//This is the default #include dependencies.
//If you want to edit this, go to Editor Options > Snippets > Default Source.

#ifndef INPUT_LIB
#define INPUT_LIB

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Function that will ask input from user, checks if it was a number, and return it. Source : http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
int inputFromCIN()
{
	int i;
	while (!(std::cin >> i)) {
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << "Invalid data type! Please enter the number again!" << std::endl;
	}
	return i;
}

int inputFromCIN(std::string errInputIsNotNumber)
{
	int i;
	while (!(std::cin >> i)) {
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << "Invalid data type! Please enter the number again!" << std::endl;
	}
	return i;
}

//Get input from cin, checks if input is format, and also checks if input is in a range
int inputFromCIN(int minimum, int maximum)
{
	while (true) {
		int i;
		std::cin >> i;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << "Your Input is Invalid. Please Enter The Number Again!" << std::endl;
			continue;
		}

		if (i < minimum || i > maximum)
		{
			std::cout << "Your Input Is Not In Range. Please Enter The Number Again!" << std::endl;
			continue;
		}

		return i;
	}
}

//Get input from cin, checks if input is format, and also checks if input is in a range
int inputFromCIN(int minimum, int maximum, std::string errNumIsNotInRange)
{
	while (true) {
		int i;
		std::cin >> i;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << "Your Input is Invalid. Please Enter The Number Again!" << std::endl;
			continue;
		}

		if (i < minimum || i > maximum)
		{
			std::cout << errNumIsNotInRange << std::endl;
			continue;
		}

		return i;
	}
}

//Get input from cin, checks if input is format, and also checks if input is in a range
int inputFromCIN(int minimum, int maximum, std::string errNumIsNotInRange, std::string errInputIsNotNumber)
{
	while (true) {
		int i;
		std::cin >> i;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << errInputIsNotNumber << std::endl;
			continue;
		}

		if (i < minimum || i > maximum)
		{
			std::cout << errNumIsNotInRange << std::endl;
			continue;
		}

		return i;
	}
}

int inputFromCIN(int minimum, int maximum, std::string errNumIsGreater, std::string errNumIsLesser, std::string errInputIsNotNumber)
{
	while (true) {
		int i;
		std::cin >> i;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << errInputIsNotNumber << std::endl;
			continue;
		}

		if (i > maximum)
		{
			std::cout << errNumIsGreater << std::endl;
			continue;
		}

		if (i < minimum)
		{
			std::cout << errNumIsLesser << std::endl;
			continue;
		}

		return i;
	}
}

#endif
