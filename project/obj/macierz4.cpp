#include "macierz4.h"

Macierz::~Macierz(){
			if(tab!=NULL){
				delete[] tab;
			}
			row=col=0;
		}

Macierz& Macierz::operator=(const Macierz& m2){
		row = m2.row;
		col = m2.col;
		tab = new double [row*col];
		std::memcpy(tab,m2.tab,row*col*sizeof(double));
		return *this;
	}

void Macierz::wczytaj(double tablica[]){
		int z = 0;
		for (int i = 0; i<row; ++i){
			for(int j = 0; j<col; ++j){
				tab[i*col+j] = tablica[z];
				++z;
			}
		}
	}
	
void Macierz::wypisz(){
		for (int i = 0; i<row; ++i){
			for(int j = 0; j<col; ++j){
				std::cout<<tab[i*col+j]<<", ";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}

double Macierz::element(int r, int c){
	if (r>row || c>col) throw;
	double elem = tab[(r-1)*col + c - 1];
	return elem;
}	

Macierz Macierz::operator+(const Macierz &m2)const{
	if (row != m2.row||col!=m2.col)throw;
	else{
		Macierz m3(row, col);
		for(int i = 0; i<col*row; ++i){
			m3.tab[i]=m2.tab[i]+tab[i];
		}
		return m3;
		}
}

Macierz Macierz::operator-(const Macierz &m2)const{
	if (row != m2.row||col!=m2.col)throw;
	else{
		Macierz m3(row, col);
		for(int i = 0; i<col*row; ++i){
			m3.tab[i]=tab[i]-m2.tab[i];
		}
		return m3;
		}
}

double Macierz::wyznacznik(){
	if (col!=row) throw 300;
	double wyznacznik = 0;
	if (row==1){
		wyznacznik = tab[0];
	}
	if (row == 2){
		wyznacznik = tab[0]*tab[3]-tab[1]*tab[2];
	}
	if (row > 2){
		double tablica[row];
		for (int k = 0;k<col;++k){
			Macierz m3(row - 1,col - 1);
			for(int i = 0; i<row - 1; ++i){
				for (int j = 0; j<col; ++j){
					if (k!=j){
						int l = j;
						if (k <= j) l=j-1;
						m3.tab[i*m3.col+l] = tab[i*col+j];
					}
				}
			}
			tablica[k] = m3.wyznacznik();
			if ((row+k+1)%2==1) tablica[k] = tablica[k]*(-1);
			tablica[k] = tablica[k]*tab[(row-1)*col+k];
		}
		for (int i = 0; i<col; ++i){
			wyznacznik = wyznacznik + tablica[i]; 
		}
	}
	return wyznacznik;
}

Macierz& Macierz::operator*(const double a){
	for(int i = 0; i<row*col; ++i){
		tab[i] = tab[i]*a;
	}
	return *this;	
}

Macierz& Macierz::operator/(const double a){
	if (a==0)throw ;
		for(int i = 0; i<row*col; ++i){
			tab[i] = tab[i]/a;
		}
	return *this;
}

Macierz Macierz::operator*(const Macierz &m2)const{
	if (col !=m2.row) throw;
	Macierz m3(row, m2.col);
	double liczba;
	for (int i = 0; i<m3.row; ++i ){
		for (int j = 0; j<m3.col; ++j){
			liczba = 0;
			for (int k = 0; k<col; ++k){
				liczba += tab[i*col+k]*m2.tab[k*m2.col+j];
			}
			m3.tab[i*m3.col+j] = liczba;
		}
	}
	return m3;
}

Macierz Macierz::transpozycja()const{
	Macierz m3(col,row);
	for(int i = 0; i<row; ++i){
		for (int j = 0; j<col; ++j){
			m3.tab[j*m3.col+i] = tab[i*col+j];
		}
	}
	return m3;
	}

bool Macierz::operator==(const Macierz &m2)const{
	if (row!=m2.row||col!=m2.col||col == 0||row==0){
		return false;
	}
	for (int i=0; i<col; ++i){
		for (int j=0; j<row; ++j){
			if (tab[i*col+j]!=m2.tab[i*col+j]){
				return false;
				}
			}
		}
	return true;
	}

bool Macierz::operator!=(const Macierz& m2)const{
	return !(*this==m2);
}

Macierz& Macierz::operator-(){
	for (int i = 0; i<row*col; ++i){
		tab[i] = tab[i]*(-1);
	}
	return *this;
	}

Macierz& Macierz::wstaw(double a, int r, int c){
	if (r>row || c>col) throw;
	tab[(r-1)*col+c-1] = a;	
	return *this;
}


