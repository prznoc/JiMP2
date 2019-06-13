#ifndef __MACIERZ4_H
#define __MACIERZ4_H

#include <iostream>
#include <cstring>

class Macierz{
	private:
		double *tab;
		unsigned int row, col;
	public:
		Macierz(unsigned int n, unsigned int m): row(n),col(m){tab = new double[row*col];}
		Macierz(const Macierz& orginal){*this = orginal;}
		~Macierz();
		Macierz& operator=(const Macierz& m2);
		void wczytaj(double tablica[]);
		void wypisz();
		double element(int r, int c);
		Macierz operator+(const Macierz &m2)const;
		Macierz operator-(const Macierz &m2)const;
		double wyznacznik();
		Macierz& operator*(const double a);
		Macierz& operator/(const double a);
		Macierz operator*(const Macierz &m2)const;
		Macierz transpozycja()const;
		bool operator==(const Macierz &m2)const;
		bool operator!=(const Macierz &m2)const;
		Macierz& operator-();
		Macierz& wstaw(double a, int r, int c);
};

#endif
