// PR Bahasa Pemrograman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include <string>

#include <random>

#include "input_lib.hpp"

using namespace std;

//Padding strings to the left. Source : https://stackoverflow.com/questions/667183/padding-stl-strings-in-c
void debugPrint(double input)
{
	cout << input << endl;
}

struct dataNilai {
	struct p {
		//Semester 3
		double s3;
		//Semester 4
		double s4;
		//Semester 5
		double s5;
		//Nilai Rata-Rata
		double n_rr;

		//Nilai Ujian Sekolah
		double n_us;
		//Nilai Sekolah
		double ns;

		//Nilai Ujian Nasional
		double n_un;
		//NilaiAkhir
		double na;

		bool lulus = false;
	} p[10];

	struct t {
		double s3;
		double s4;
		double s5;
		double n_rr = (s3 + s4 + s5) / 3;

		double n_us;
		double ns;

		double n_un;
		double na;

		bool lulus = false;
	} t;

	/*
	struct t {
		double s3 = (dn.p[0].s3 + dn.p[1].s3 + dn.p[2].s3 + dn.p[3].s3 + dn.p[4].s3 + dn.p[5].s3) / 6;
		double s4 = (dn.p[0].s4 + dn.p[1].s4 + dn.p[2].s4 + dn.p[3].s4 + dn.p[4].s4 + dn.p[5].s4) / 6;
		double s5 = (dn.p[0].s5 + dn.p[1].s5 + dn.p[2].s5 + dn.p[3].s5 + dn.p[4].s5 + dn.p[5].s5) / 6;
		double n_rr = (s3 + s4 + s5) / 3;

		double n_us = (dn.p[0].n_us + dn.p[1].n_us + dn.p[2].n_us + dn.p[3].n_us + dn.p[4].n_us + dn.p[5].n_us) / 6;
		double ns = (0.7 * n_rr) + (0.3 * n_us);

		double n_un = (dn.p[0].n_un + dn.p[1].n_un + dn.p[2].n_un + dn.p[3].n_un + dn.p[4].n_un + dn.p[5].n_un) / 6;
		double na = (0.4 * ns) + (0.6 * n_un);
	} t;
	*/

	string nama_p[6] = { "Bahasa Indonesia", "Bahasa Inggris", "Matematika", "Fisika", "Kimia", "Biologi" };
};

int main()
{
	dataNilai dn;
	mt19937_64 mtEngine;

	uniform_int_distribution<int> distribute(60, 100);
	do
	{
		for (int i = 0; i < 6;i++)
		{
			printf("p "); cout << dn.nama_p[i] << endl << endl;
			printf("Masukkan Nilai Semester 3 : "); dn.p[i].s3 = distribute(mtEngine);
			printf("Masukkan Nilai Semester 4 : "); dn.p[i].s4 = distribute(mtEngine);
			printf("Masukkan Nilai Semester 5 : "); dn.p[i].s5 = distribute(mtEngine);
			printf("Masukkan Nilai Ujian Sekolah : "); dn.p[i].n_us = distribute(mtEngine);
			printf("Masukkan Nilai Ujian Nasional : "); dn.p[i].n_un = distribute(mtEngine);
			printf("\n\n");

			cout << "Semester3 : " << endl;
			for (int i = 0; i < 6; i++)
			{
				debugPrint(dn.p[i].s3);
			}
			cout << endl;
			debugPrint((dn.p[0].s3 + dn.p[1].s3 + dn.p[2].s3 + dn.p[3].s3 + dn.p[4].s3 + dn.p[5].s3) / 6);
			cout << endl;
			cout << "Semester4 : " << endl;
			for (int i = 0; i < 6; i++)
			{
				debugPrint(dn.p[i].s4);
			}
			cout << endl;
			debugPrint((dn.p[0].s4 + dn.p[1].s4 + dn.p[2].s4 + dn.p[3].s4 + dn.p[4].s4 + dn.p[5].s4) / 6);
			cout << endl;
			cout << "Semester5 : " << endl;
			for (int i = 0; i < 6; i++)
			{
				debugPrint(dn.p[i].s5);
			}

			cout << endl;
			debugPrint((dn.p[0].s5 + dn.p[1].s5 + dn.p[2].s5 + dn.p[3].s5 + dn.p[4].s5 + dn.p[5].s5) / 6);
			cout << endl;

			dn.p[i].n_rr = (dn.p[i].s3 + dn.p[i].s4 + dn.p[i].s5) / 3;

			dn.p[i].ns = (0.7 * dn.p[i].n_rr) + (0.3 * dn.p[i].n_us);

			dn.p[i].na = (0.4 * dn.p[i].ns) + (0.6 * dn.p[i].n_un);

			cout << "Grade : " << dn.p[i].na << endl;
			if (dn.p[i].na >= 40) {
				dn.p[i].lulus = true;
				cout << "One of the Stuff not passed" << endl;
			}
		}

		dn.t.s3 = (dn.p[0].s3 + dn.p[1].s3 + dn.p[2].s3 + dn.p[3].s3 + dn.p[4].s3 + dn.p[5].s3) / 6;
		dn.t.s4 = (dn.p[0].s4 + dn.p[1].s4 + dn.p[2].s4 + dn.p[3].s4 + dn.p[4].s4 + dn.p[5].s4) / 6;
		dn.t.s5 = (dn.p[0].s5 + dn.p[1].s5 + dn.p[2].s5 + dn.p[3].s5 + dn.p[4].s5 + dn.p[5].s5) / 6;
		dn.t.n_rr = (dn.t.s3 + dn.t.s4 + dn.t.s5) / 3;

		dn.t.n_us = (dn.p[0].n_us + dn.p[1].n_us + dn.p[2].n_us + dn.p[3].n_us + dn.p[4].n_us + dn.p[5].n_us) / 6;;
		dn.t.ns = (0.7 * dn.t.n_rr) + (0.3 * dn.t.n_us);
		dn.t.n_un = (dn.p[0].n_un + dn.p[1].n_un + dn.p[2].n_un + dn.p[3].n_un + dn.p[4].n_un + dn.p[5].n_un) / 6;
		dn.t.na = (0.4 * dn.t.ns) + (0.6 * dn.t.n_un);

		cout << "=============================================" << endl << endl;

		printf("Nilai Rata-Rata Semester 3 : %.2f\n", dn.t.s3);
		printf("Nilai Rata-Rata Semester 4 : %.2f\n", dn.t.s4);
		printf("Nilai Rata-Rata Semester 5 : %.2f\n", dn.t.s5);
		printf("Nilai Rata-Rata Seluruh Semester : %.2f\n", dn.t.n_rr);
		printf("Nilai Rata-Rata US: %.2f\n", dn.t.n_us);
		printf("Nilai Rata-Rata Nilai Sekolah: %.2f\n", dn.t.ns);
		printf("Nilai Rata-Rata UN : %.2f\n", dn.t.n_un);
		printf("Nilai Rata-Rata Ujian Akhir : %.2f\n", dn.t.na);
		cout << endl;

		bool lulus = true;
		for (int i = 0; i < 6; i++)
		{
			if (!dn.p[i].lulus) {
				cout << "Found False on Pass Test" << endl;
				lulus = false;
				break;
			}
		}
		if (!dn.t.lulus)
		{
			lulus = false;
		}

		string keterangan = "TIDAK LULUS";
		if (lulus)
			keterangan = "LULUS";
		cout << "Keterangan : " << keterangan << endl;

		_getch();
		system("cls");
	} while (true);
	return 0;
}