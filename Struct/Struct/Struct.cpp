// Struct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include <string>

using namespace std;

struct mahasiswa
{
	int nim;
	string nama;
	int umur;
	float ipk;
} mhs;

void show()
{
	cout << "--- Input --- \n\n";
	cout << "NIM		= " << mhs.nim << endl
		 << "Nama		= " << mhs.nama << endl
		 << "Umur		= " << mhs.umur << endl
		 << "IPK		= " << mhs.ipk << endl;
}

void input()
{
	cout << "Masukkan NIM " << endl;
	cin >> mhs.nim;
	cout << "Masukkan Nama " << endl;
	cin >> mhs.nama;
	cout << "Masukkan Umur " << endl;
	cin >> mhs.umur;
	cout << "Masukkan IPK " << endl;
	cin >> mhs.ipk;
}

int main()
{
	cout << "Irashaimasen~";
	input();

	show();
    return 0;
}

