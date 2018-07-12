#ifndef PLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYER_H

#include <iostream>
#include <conio.h>

int inputFromCIN();
int inputFromCIN(std::string errInputIsNotNumber);
int inputFromCIN(int minimum, int maximum);
int inputFromCIN(int minimum, int maximum, std::string errNumIsNotInRange);
int inputFromCIN(int minimum, int maximum, std::string errNumIsNotInRange, std::string errInputIsNotNumber);
int inputFromCIN(int minimum, int maximum, std::string errNumIsGreater, std::string errNumIsLesser, std::string errInputIsNotNumber);

#endif