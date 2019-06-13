#include <iostream>


class macierz{
	private:
		double *tab;
		unsigned int row, col;
	public:
		macierz(unsigned int n, unsigned int m): row(n),col(m){tab = new double[row*col];}
		macierz(const macierz& orginal){
			*this = orginal;
		}
	
	~macierz(){
			if(tab!=NULL){
				delete[] tab;
			}
			row=col=0;
		}
	
	macierz& operator=(const macierz& m2){
		row = m2.row;
		col = m2.col;
		tab = new double [row*col];
		memcpy(tab,m2.tab,row*col*sizeof(double));
		return *this;
	}
	
	void wczytaj(double tablica[]){
		int z = 0;
		for (int i = 0; i<row; ++i){
			for(int j = 0; j<col; ++j){
				tab[i*col+j] = tablica[z];
				++z;
			}
		}
	}
	
	void wypisz(){
		for (int i = 0; i<row; ++i){
			for(int j = 0; j<col; ++j){
				std::cout<<tab[i*col+j]<<", ";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	
	double element(int r, int c){
		try{
			if (r>row || c>col) throw 300;
			double elem = tab[(r-1)*col + c - 1];
			std::cout<<elem<<std::endl;
			return elem;
		}
		catch(...){
			std::cerr <<"Szukany element wykracza poza rozmiar macierzy"<<std::endl;;
		}
	}	
	
	macierz operator+(const macierz &m2)const{
		try{
			if (row != m2.row||col!=m2.col)throw 300;
			else{
				macierz m3(row, col);
				for(int i = 0; i<col*row; ++i){
					m3.tab[i]=m2.tab[i]+tab[i];
				}
				return m3;
			}
		}
			catch(...){
				std::cout<<"Wrong matrix dimensions"<<std::endl;
			}
	}
	
	macierz operator-(const macierz &m2)const{
		
		try{
			if (row != m2.row||col!=m2.col)throw 300;
			else{
				macierz m3(row,col);
				for(int i = 0; i<col*row; ++i){
					m3.tab[i]=tab[i]-m2.tab[i];
				}
				return m3;
			}
		}
			catch(...){
				std::cout<<"Wrong matrix dimensions"<<std::endl;
			}
	
	}
	
	double wyznacznik(){
		try{
			if (col!=row) throw 300;
			double wyznacznik = 0;
			if (row==1){
				wyznacznik = tab[0];
			}
			if (row == 2){
				wyznacznik = tab[0]*tab[3]-tab[1]*tab[2];
			}
			if (row > 2){
				double tablica[col];
				for (int k = 0;k<col;++k){
					macierz m3(row - 1,col - 1);
					for(int i = 0; i<row - 1; ++i){
						for (int j = 0; j<col; ++j){
							int l = j;
							if (k <= j) {
								l=j-1;
							}
							if (k!=j){
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
		catch(...){
			std::cout<<"macierz nie jest kwadratowa"<<std::endl;
		}
	}
	
	macierz &operator*(const double a){
		for(int i = 0; i<row*col; ++i){
			tab[i] = tab[i]*a;
		}
		return *this;
	}
	
	macierz &operator/(const double a){
		try{
			if (a==0)throw 300;
			for(int i = 0; i<row*col; ++i){
				tab[i] = tab[i]/a;
			}
			return *this;
		}
		catch(...){
			std::cout<<"Nie mo¿na dzieliæ przez 0"<<std::endl;
		}
	}
	
	macierz operator*(const macierz &m2){
			if (col !=m2.row) throw;
			macierz m3(row, m2.col);
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
	
	macierz transpozycja()const{
		macierz m3(col,row);
		for(int i = 0; i<row; ++i){
			for (int j = 0; j<col; ++j){
				m3.tab[j*m3.col+i] = tab[i*col+j];
			}
		}
		return m3;
	}
	
	bool operator==(const macierz &m2)const{
		if (row!=m2.row||col!=m2.col||col == 0){
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
	
	bool operator!=(const macierz &m2)const{
		if (row!=m2.row||col!=m2.col||col == 0){
			return true;
		}
		for (int i=0; i<col; ++i){
			for (int j=0; j<row; ++j){
				if (tab[i*col+j]!=m2.tab[i*col+j]){
					return true;
					}
				}
			}
		return false;
	}

	macierz &operator-(){
		for (int i = 0; i<row*col; ++i){
			tab[i] = tab[i]*(-1);
		}
		return *this;
	}
	
	macierz &wstaw(double a, int r, int c){
		try{
			if (r>row || c>col) throw 300;
			tab[(r-1)*col+c-1] = a;
			return *this;
		}
		catch(...){
			std::cerr <<"Szukany element wykracza poza rozmiar macierzy"<<std::endl;;
		}
	}
};

macierz operator*(double liczba,macierz &m2){
	return m2*liczba;
}

int main(){
	double tablica1[] = {1,2,3,5,5,6,7,8,9,10,11,12};
	double tablica2[] = {5,3,4,56,78,4,2,2,3,2,5,6};
	double tablica3[] = {15,18,15,65,564,48,1468,1468,1,135,132,132,1,14683, 46,46};
	macierz m1(4,3);
	macierz m2(3,4);
	macierz m3(4,4);
	m1.wczytaj(tablica1);
	m2.wczytaj(tablica2);
	m3.wczytaj(tablica3);
	macierz m4 = m1*m2;
	macierz m5 = m4*m3;
	m5.wypisz();
	macierz m6 = m2*m3;
	macierz m7 = m1*m6;
	m7.wypisz();
	return 0;	
}
