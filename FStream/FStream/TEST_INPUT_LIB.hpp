//This is the default #include dependencies.
//If you want to edit this, go to Editor Options > Snippets > Default Source.

#ifndef INPUT_LIB
#define INPUT_LIB

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*
Function that will ask input from user, checks if it was a number, and return it. Source : http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
*/

/*
LICENSE INFO
================================================================================
MIT License

Copyright (c) 2017 Rogan Matrivski L. / Robin Mauritz Languju

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

//Takes input from CIN, and then return the integer.
int inputFromCIN()
{
	int i;
	while (!(std::cin >> i)) {
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << "Invalid data type! Please enter the number again!" << std::endl;
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return i;
}

//Takes input from CIN, display custom messages if it's not a number, and then return the integer.
int inputFromCIN(std::string errInputIsNotNumber)
{
	int i;
	while (!(std::cin >> i)) {
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << errInputIsNotNumber << std::endl;
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return i;
}

//Takes input from CIN, checks if it's inbetween 0 and maximum, and then return the integer.
int inputFromCIN(int maximum)
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

		if (i < 0 || i > maximum)
		{
			std::cout << "Your Input Is Not In Range. Please Enter The Number Again!" << std::endl;
			continue;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return i;
	}
}

//Takes input from CIN, checks if it's inbetween minimum and maximum, and then return the integer.
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

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return i;
	}
}

//Takes input from CIN, checks if it's inbetween minimum and maximum, display custom message if input is not in range, and then return the integer.
int inputFromCIN(int minimum, int maximum, std::string errNumIsNotValid)
{
	while (true) {
		int i;
		std::cin >> i;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << errNumIsNotValid << std::endl;
			continue;
		}

		if (i < minimum || i > maximum)
		{
			std::cout << errNumIsNotValid << std::endl;
			continue;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return i;
	}
}

//Takes input from CIN, checks if it's inbetween minimum and maximum, display custom message if input is not in range or invalid, and then return the integer.
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

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return i;
	}
}

//Takes input from CIN, checks if it's inbetween minimum and maximum, display custom message if input is below minimum, maximum or invalid data type, and then return the integer.
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

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return i;
	}
}

#endif
