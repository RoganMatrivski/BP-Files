// FStream.cpp : Defines the entry point for the console application.
//

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

#include "stdafx.h"
#include <iostream>
#include <conio.h>

#include <cstdlib>
#include <fstream>

#include <random>
#include <string>

#include <chrono>

#include "TEST_INPUT_LIB.hpp"

using namespace std;

struct mahasiswa
{
	string nama;
};

uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

mahasiswa ueu;

int garis()
{
	cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
	return 0;
}

mt19937_64 mtEngine(seed);

int returnRandomNumber(int min, int max)
{
	uniform_int_distribution<int> mtDist(min, max);
	
	return mtDist(mtEngine);
}

int clche()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return 0;
}

string randomString(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[returnRandomNumber(0, max_index)];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

int createRandomData(string filePath)
{
	ofstream output;
	uniform_int_distribution<int> mtDist(512, 1024);
	output.open(filePath);
	if (output.is_open())
	{
		for (int i = 0; i < mtDist(mtEngine); i++)
		{
			for (int j = 0; j < 1024; j++)
			{
				output << randomString(64) << endl;
			}
		}
		output.close();
	}
	else
	{
		return -1;
	}
	return 0;
}

int readData(string filePath)
{
	ifstream input;
	string line;
	input.open(filePath);

	cout << "Below is the content of " << filePath << endl << endl;

	if (input.is_open())
	{
		while (getline(input, line))
		{
			cout << line << endl;
		}

		input.close();
	}
	else
		return 1;
	
	return 0;
}

std::vector<string> readDataToVector(string filePath)
{
	ifstream input;
	string line;
	std::vector<string> lists;
	input.open(filePath);
	if (input.is_open())
	{
		while (getline(input, line))
		{
			lists.push_back(line);
		}

		input.close();
	}
	
	return lists;
}

std::vector<string> mergeVector(std::vector<string> vec1, std::vector<string> vec2)
{
	std::vector<string> vec3 = vec1;

	vec3.insert(vec3.end(), vec2.begin(), vec2.end());

	return vec3;
}

int writeVector(string filepath, std::vector<string> vector)
{
	fstream output;
	output.open(filepath, ios::out);
	if (output.is_open())
	{
		for (int i = 0; i < vector.size(); i++)
		{
			output << vector[i] << endl;
		}

		output.close();
	}
	else
	{
		return 1;
	}

	return 0;
}

int mergeFiles(string filePath, string secondFilePath, string destFilePath)
{
	std::vector<string> file1 = readDataToVector(filePath);
	std::vector<string> file2 = readDataToVector(secondFilePath);
	std::vector<string> finalFile = mergeVector(file1, file2);

	if (writeVector(destFilePath, finalFile))
	{
		cout << "Failed to create data. Path is probably invalid or need Admin previleges." << endl;
	}
	else
	{
		cout << "Successfully created an empty file on " << destFilePath << endl;
	}

	return 0;
}



int createData(string filePath)
{
	fstream output;
	output.open(filePath, ios::out);
	if (output.is_open())
	{
		//output << "" << endl;
		output.close();
	}
	else
	{
		return 1;
	}
	return 0;
}

int appendData(string filepath)
{
	std::vector<string> data = readDataToVector(filepath);

	cout << "Write any line to append to file. Add \"[END]\" to exit." << endl << endl;

	string line;
	do
	{
		getline(cin, line);
		data.push_back(line);
	} while (data[data.size()-1] != "[END]");

	data.pop_back();
	if (writeVector(filepath, data))
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return 0;
}

int main()
{
	while (true)
	{
		cout << "=======================================================" << endl;
		cout << "		FStream Practice" << endl;
		cout << "=======================================================" << endl;
		cout << endl;

		cout << "Please Enter The Operation You Want to do." << endl;

		cout << "--------------------------------------------------------" << endl;
		cout << "1. Create New Text File" << endl;
		cout << "2. Add(Append) Text to File." << endl;
		cout << "3. Display Text File" << endl;
		cout << "4. Merge Text File" << endl;
		cout << "5. Exit" << endl;
		cout << endl;

	
		int choosen = inputFromCIN(1, 5); //inputFromCIN is my custom function to input number without hassle. Refer to TEST_INPUT_LIB.CPP.
		switch (choosen)
		{
			case 1:
			{
				system("CLS");
				string filepath;
				cout << "Insert File Path" << endl;
				getline(cin, filepath);
				if (createData(filepath))
				{
					cout << "Failed to create data. Path is probably invalid or need Admin previleges." << endl;
				}
				else
				{
					system("CLS");
					if (appendData(filepath))
					{
						system("CLS");
						cout << "Failed to create data. Path is probably invalid or need Admin previleges." << endl;
					}
					else
					{
						system("CLS");
						cout << "Successfully Created Data On " << filepath << endl;
					}
				}
				break;
			}
			case 2:
			{
				system("CLS");
				string filepath;
				cout << "Insert File Path" << endl;
				getline(cin, filepath);
				system("CLS");
				if (appendData(filepath))
				{
					system("CLS");
					cout << "Failed to create data. Path is probably invalid or need Admin previleges." << endl;
				}
				else
				{
					system("CLS");
					cout << "Successfully Saved Data On " << filepath << endl;
				}
				break;
			}
			case 3:
			{
				system("CLS");
				string filepath;
				cout << "Insert File Path" << endl;
				getline(cin, filepath);
				system("CLS");
				if (readData(filepath))
				{
					cout << "Failed to read data. Path is probably invalid or need Admin previleges." << endl;
				}
				break;
			}
			case 4:
			{
				system("CLS");
				string filepath;
				string filepath2;
				string destpath;
				cout << "Insert First File Path" << endl;
				getline(cin, filepath);
				cout << "Insert Second File Path" << endl;
				getline(cin, filepath2);
				cout << "Insert Destination File Path" << endl;
				getline(cin, destpath);

				mergeFiles(filepath, filepath2, destpath);

				break;
			}

			case 5:
			{
				exit(0);
			}

			default:
			{
				cout << "Selection Invalid. Try Again" << endl;
				break;
			}
		}
		clche();
		cout << endl <<"Press Any Key to Continue" << endl;
		_getch();
		system("CLS");
	}
    return 0;
}


