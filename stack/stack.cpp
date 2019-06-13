#include <iostream>
#include "stack.h"

template <typename T>
void Stos<T>::push(T value){
	Node <T> *added;
	added = new Node<T> (value);
	if (top == NULL){
		top = added;
		size += 1;
	}
	else{
		added->prev = top;
		top = added;
		size += 1;
	}
}

template <typename T>
T Stos<T>::pop(){
	if (size <=0){
		throw;
	}
	else if (size == 1){
		T value = top->elem;
		delete top;
		size = 0;
		return value;
	}
	else{
		Node <T> *temp = top;
		T value = top->elem;
		top = top->prev;
		delete temp;
		size -= 1;
		return value;
	}
}

template <typename T>
bool Stos<T>::is_empty()const{
	if (size == 0) return true;
	else if(size >0) return false;
}

template <typename T>
void Stos<T>::clear(){
	while(size>0) this->pop();
}

template <typename T>
int Stos<T>::rozmiar()const{
	return size;
}

int main(void){
	Stos <int> stos;
	Stos <int> stos2;
	stos.push(5);
	stos.push(6);
	stos.push(7);
	stos.push(8);
	std::cout<<stos.pop();
}
