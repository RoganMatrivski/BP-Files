// Lat BP 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

#include <string>
#include <vector>

#include <random>
#include <chrono>
#include <limits>

#include "TEST_INPUT_LIB.hpp"

using namespace std;

typedef struct
{
	int tgl;
	int bln;
	int th;
}Tanggal;

typedef struct
{
	string noID;
	string nama;
	char jenis_kelamin; //’L’ atau ‘P’
	Tanggal t;
}KTP;

typedef struct
{
	vector<KTP> ktp;
	int jml;
}Data_KTP;

Data_KTP data_ktp;
Data_KTP *p;

int randomNum(int max)
{
	mt19937_64 mtEngine(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> mtDist(0, max);
	return mtDist(mtEngine);

}

int randomNum(int min, int max)
{
	mt19937_64 mtEngine(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> mtDist(min, max);
	return mtDist(mtEngine);

}

std::string randomString(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

char returnGender()
{
	char letters[] = "LP";
	char x = letters[randomNum(1)];
	return x;
}



KTP debugKTP()
{
	KTP temp;

	temp.t.th = randomNum(1990, 2050);
	temp.t.bln = randomNum(12);
	temp.t.tgl = randomNum(30);

	temp.nama = randomString(30);
	temp.noID = randomString(5);

	temp.jenis_kelamin = returnGender();

	return temp;
}

KTP inputKTP()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	KTP temp;

	cout << "Input Nama Anda.";
	getline(cin, temp.nama);

	cout << "Input No ID Anda.";
	getline(cin, temp.noID);

	cout << "Input Tanggal Lahir Anda.";
	temp.t.tgl = inputFromCIN(1, 31);
	cout << "Input Bulan Lahir Anda.";
	temp.t.bln = inputFromCIN(1, 12);
	cout << "Input Tahun Lahir Anda.";
	temp.t.th = inputFromCIN(1900, 2050);

	
	
	cout << "Input Jenis Kelamin Anda.";
	cin >> temp.jenis_kelamin;

	temp.jenis_kelamin = toupper(temp.jenis_kelamin);
	return temp;
}

KTP replaceKTP()
{
	cin.clear();	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	KTP temp;
	
	cout << "Input Nama Anda.";
	getline(cin, temp.nama);

	cout << "Input No ID Anda.";
	getline(cin, temp.noID);

	cout << "Input Tanggal Lahir Anda.";
	temp.t.tgl = inputFromCIN(1, 31);
	cout << "Input Bulan Lahir Anda.";
	temp.t.bln = inputFromCIN(1, 12);
	cout << "Input Tahun Lahir Anda.";
	temp.t.th = inputFromCIN(1900, 2050);

	cout << "Input Jenis Kelamin Anda.";
	cin >> temp.jenis_kelamin;
	temp.jenis_kelamin = toupper(temp.jenis_kelamin);


	return temp;
}

/*
void editKTP(Data_KTP *pointer, int position)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

auto temp = pointer->ktp[position];

cout << "Input Nama Anda.";
getline(cin, temp.nama);

cout << "Input No ID Anda.";
getline(cin, temp.noID);

cout << "Input Tanggal Lahir Anda.";
temp.t.tgl = inputFromCIN(1, 31);
cout << "Input Bulan Lahir Anda.";
temp.t.bln = inputFromCIN(1, 12);
cout << "Input Tahun Lahir Anda.";
temp.t.th = inputFromCIN(1900, 2050);



cout << "Input Jenis Kelamin Anda.";
cin >> temp.jenis_kelamin;

cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
*/

void printKTP(KTP input)
{
	printf("No ID			: "); cout << input.noID << endl;
	printf("Nama			: "); cout << input.nama << endl;
	printf("Tanggal			: %d/%d/%d\n", input.t.tgl, input.t.bln, input.t.th);
	printf("Jenis Kelamin		: %c\n", input.jenis_kelamin);

}

int main()
{
	while (true)
	{
		Data_KTP *p = &data_ktp;

		unsigned int choosedOperation = 0;

		cout << "=======================================================" << endl;
		cout << "		Program" << endl;
		cout << "=======================================================" << endl;
		cout << endl;

		cout << "Please Enter The Operation You Want to do." << endl;

		cout << "--------------------------------------------------------" << endl;
		cout << "1. Add Records" << endl;
		cout << "2. Find Data Based on Birth Year" << endl;
		cout << "3. Display Data Based on Gender" << endl;
		cout << "4. Edit Data" << endl;
		cout << endl;

		//Checks if input is a number or not. Source : https://stackoverflow.com/questions/3273993/how-do-i-validate-user-input-as-a-double-in-c

		while (choosedOperation > 4 || choosedOperation < 1)
		{
			choosedOperation = inputFromCIN(1, 4);

			switch (choosedOperation)
			{
			case 1:
			{
				p->ktp.push_back(inputKTP());


				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;

			case 2:
			{
				cout << "Insert The Year : "; int yearSelected = inputFromCIN(1950, 2050);

				for (int i = 0; i < p->ktp.size(); i++)
				{
					if (p->ktp[i].t.th == yearSelected)
					{
						cout << "Record KTP No. " << i << endl;
						printKTP(p->ktp[i]);
						printf("\n\n");
					}
				}
			}
			break;

			case 3:
			{
				char choosenGender; cin >> choosenGender;

				for (int i = 0; i < p->ktp.size(); i++)
				{
					if (p->ktp[i].jenis_kelamin == (choosenGender = toupper(choosenGender)))
					{
						cout << "Record KTP No. " << i << endl;
						printKTP(p->ktp[i]);
						printf("\n\n");
					}
				}
			}
			break;

			case 4:
			{
				cout << "Please Input The Position of The Record You Want To Edit : "; int recPos = inputFromCIN(0, p->ktp.size()); cout << endl;

				p->ktp[0] = replaceKTP();
				cout << "\nEdited Data : \n";
				printKTP(p->ktp[0]);
			}
			break;

			default:
				cout << "Invalid Selection. Please check your input again." << endl;
				break;
			}
		}

		cout << endl << "Operation Done!" << endl;

		_getch();
		_getch();
		_getch();
		system("CLS");
	}
}

