#include <iostream>
#include "tablica.h"

template <typename T>
void Array<T>::copy(T *left, T *right){
	for (int i = 0; i<size; ++i){
		left[i] = right[i];
	}
}

template <typename T>
void Array<T>::push_back(const T &dane){
	if (size>=max){
		max = max+10;
		T *temp = new T[max];
		copy(temp, tablica);
		delete[] tablica;
		tablica = temp;
	}
	tablica[size] = dane;
	size+=1;
}

template <typename T>
T Array<T>::pop_back(){
	if (size>0){
	T zwrot;
	zwrot = tablica[size-1];
	tablica[size-1] = 0;
	size -=1;
	return zwrot;
	}
	else throw;
}

template <typename T>
T& Array<T>::operator[](int pos){
	if(pos>=0&&pos<size){
		return tablica[pos];
	}
	else throw;
}

template <typename T>
void Array<T>::add(const T dane, int pos){
	if(pos<0||pos>=size) throw;
	else{
		tablica[pos] = dane;
	}
}

template <typename T>
void Array<T>::clear(){
	for (int i = 1; i<=size; ++i){
		tablica[i] = 0;
	}
}

template <typename T>
int Array<T>::rozmiar()const{
	return size;
}

int main(){
	Array <int> tablica(10);
	for (int i = 0; i<=23; ++i){
		tablica.push_back(i+1);
	}
	tablica.add(12,20);
	tablica[7] = 3;
	Array<int>::iterator iter(tablica);
	iter++;
	std::cout<<*iter;
}
