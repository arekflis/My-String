#include <iostream>
#include "String.h"
using namespace std;


	STRING::STRING() : BUFFER(nullptr), size(0) {}

	STRING::STRING(const char* BUFF){
		int count = 0;
		while (BUFF[count] != '\0') {
			this->size++;
			count++;
		}
		this->BUFFER = new char[this->size + 1];
		for (int k = 0; k < this->size; k++) {
			this->BUFFER[k] = BUFF[k];
		}
		this->BUFFER[this->size] = '\0';
	}

	STRING::STRING(char tab[], int size) {
		this->size = size;
		this->BUFFER = new char[size + 1];
		for (int k = 0; k < size; k++) {
			this->BUFFER[k] = tab[k];
		}
		this->BUFFER[size] = '\0';
	}

	STRING::STRING(const STRING& OBJECT){
		this->size = OBJECT.size;
		this->BUFFER = new char[this->size + 1];
		for (int k = 0; k < this->size; k++) {
			this->BUFFER[k] = OBJECT.BUFFER[k];
		}
		this->BUFFER[this->size] = '\0';
	}

	bool STRING::operator==(STRING& OBJECT) {
		if (OBJECT.size != this->size) return false;
		else {
			for (int j = 0; j < this->size; j++) {
				if (this->GetConcreteElement(j) != OBJECT.GetConcreteElement(j))
					return false;
			}
		}
		return true;
	}

	STRING& STRING::operator=(const STRING& OBJECT) {
		if (&OBJECT != this) {
			clean();
			this->size = OBJECT.size;
			this->BUFFER = new char[this->size + 1];
			for (int k = 0; k < this->size; k++) {
				this->BUFFER[k] = OBJECT.BUFFER[k];
			}
			this->BUFFER[this->size] = '\0';
		}
		return *this;
	}

	STRING STRING::operator+(const STRING& OBJECT){
		STRING s;
		s.size = this->size + OBJECT.size;
		s.BUFFER = new char[s.size + 1];
		for (int k = 0; k < this->size; k++) {
			s.BUFFER[k] = this->BUFFER[k];
		}
		for (int k = this->size, j = 0; j < OBJECT.size, k < s.size; k++, j++) {
			s.BUFFER[k] = OBJECT.BUFFER[j];
		}
		s.BUFFER[s.size] = '\0';
		return s;
	}

	int STRING::length() const{
		return this->size;
	}
	
	STRING STRING::WithoutLastElement() {
		this->size--;
		this->BUFFER[size] = '\0';
		return *this;
	}

	STRING STRING::WithoutFirstElement() {
		for (int i = 0; i < this->size; i++) {
			this->BUFFER[i] = this->BUFFER[i + 1];
		}
		this->size--;
		this->BUFFER[size] = '\0';
		return *this;
	}

	STRING::~STRING(){
		clean();
	}

	char STRING::GetConcreteElement(int j) const{
		return this->BUFFER[j];
	}


	void STRING::clean(){
		if (this->BUFFER != nullptr){
			delete[] this->BUFFER;
		}
		this->size = 0;
	}


	ostream& operator<<(ostream& out, STRING& OBJECT){
		for (int k = 0; k < OBJECT.length(); k++) {
			out << OBJECT.GetConcreteElement(k);
		}
		return out;
	}
	istream& operator>>(istream& IS, STRING& OBJECT) {
		char* buff = new char[50000];
		IS >> buff;
		OBJECT = STRING(buff);
		delete[] buff;
		return IS;
	}
