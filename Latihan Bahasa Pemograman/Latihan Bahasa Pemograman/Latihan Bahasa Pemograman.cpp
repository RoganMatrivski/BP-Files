// Latihan Bahasa Pemograman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "TEST_INPUT_LIB.hpp"

using namespace std;

string toUpperCase(string input)
{
	for (size_t i = 0; i < input.size(); ++i)
		input[i] = toupper(input[i]);

	return input;
}

int program1()
{
	double multDiskon[] = { 0.5, 0.4, 0.3, 0.2, 0.0 };
	cout << "Silahkan Masukkan Harga Barang." << endl;
	int hargaBarang = inputFromCIN();
	int choosen = 0;

	while (true) {
		cout << "Silahkan Masukkan Kode Barang." << endl;
		char kodeBarang; cin >> kodeBarang;
		kodeBarang = toupper(kodeBarang);
		cout << "Harga Barang Awal Adalah			: " << hargaBarang << endl;
		if (kodeBarang == 'A')
		{
			choosen = 0;
			break;
		}
		if (kodeBarang == 'B')
		{
			choosen = 1;
			break;
		}
		if (kodeBarang == 'C')
		{
			choosen = 2;
			break;
		}
		if (kodeBarang == 'D')
		{
			choosen = 3;
			break;
		}
		if (kodeBarang == 'E')
		{
			choosen = 4;
			break;
		}
		cout << "Invalid Input." << endl;
	}

	hargaBarang -= hargaBarang*multDiskon[choosen];
	cout << "Besar Diskon					: " << multDiskon[choosen]*100 << "%" << endl;
	cout << "Harga Barang Akhir Adalah			: " << hargaBarang << endl;
	return 0;
}

int program2()
{
	cout << "Silahkan Masukkan Nilai Tugas." << endl;
	int nilaiTugas = inputFromCIN(0, 100);
	cout << "Silahkan Masukkan Nilai Mid Semester." << endl;
	int nilaiMid = inputFromCIN(0, 100);
	cout << "Silahkan Masukkan Nilai Akhir." << endl;
	int nilaiAkhir = inputFromCIN(0, 100);
	int nilaiFinal = (0.2 * nilaiTugas) + (0.3 * nilaiMid) + (0.5 * nilaiAkhir);

	char grade;

		if (nilaiFinal >= 0 && nilaiFinal < 50)
		{
			grade = 'E';
		}

		if (nilaiFinal >= 50 && nilaiFinal < 65)
		{
			grade = 'D';
		}

		if (nilaiFinal >= 65 && nilaiFinal < 75)
		{
			grade = 'C';
		}

		if (nilaiFinal >= 75 && nilaiFinal < 85)
		{
			grade = 'B';
		}

		if (nilaiFinal >= 85 && nilaiFinal < 100)
		{
			grade = 'A';
		}

	cout << "Nilai Tugas Anda Adalah			: " << nilaiTugas << endl;
	cout << "Nilai Mid Semester Anda Adalah		: " << nilaiMid << endl;
	cout << "Nilai Akhir Anda Adalah			: " << nilaiAkhir << endl;
	cout << "Hasil Akhir Nilai Anda Adalah		: " << nilaiFinal << endl;

	cout << "Grade Anda Adalah			: " << grade << endl;

	_getch();

	return 0;
}


int main()
{
	cout << "Silahkan Pilih Program Untuk Dijalankan." << endl;

	cout << "--------------------------------------------------------" << endl;
	cout << "1. Program yang Menghitung Diskon Harga." << endl;
	cout << "2. Program yang Menghitung Nilai Akhir." << endl;

	int choosen = inputFromCIN(1, 2);

	switch (choosen)
	{
	case 1:
		program1();
		break;
	case 2:
		program2();
		break;
	default:
		break;
	}

	_getch();

    return 0;
}

