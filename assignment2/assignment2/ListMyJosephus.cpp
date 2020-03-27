#include "ListMyJosephus.h"

//constructor
ListMyJosephus::ListMyJosephus(){
	this->size = 0;
	this->N = 0;
	this->M = 0;
}

//constructor with variables
ListMyJosephus::ListMyJosephus(int N, int M){
	this->N = N;
	this->size = N;
	this->M = M;
	Person newPerson;
	// creates Persons and gives them position i
	for(int i = 0; i < N; i++) {
		newPerson.setPosition(i);
		this->circ.push_back(newPerson);
	}
}

ListMyJosephus::~ListMyJosephus(){
	// destroys all nodes in the list
	this->circ.clear();
}

void ListMyJosephus::init(int N, int M) {
        this->N = N;
        this->size = N;
        this->M = M;
        Person newPerson;
        // creates Persons and gives them position i 
        for(int i = 0; i < N; i++) {
                newPerson.setPosition(i);
                this->circ.push_back(newPerson);
        }
}

// same code as destructor because it works I think
void ListMyJosephus::clear() {
    this->circ.clear();
	size = 0;
}

int ListMyJosephus::currentSize() {
	return this->size;
}

bool ListMyJosephus::isEmpty() {
	return this->circ.empty();
}

Person ListMyJosephus::eliminateNext(list<Person>::iterator temp) {
	Person yo; 
	yo = *temp;
	this->size--;
	temp = circ.erase(temp);
	return yo; 
}

void ListMyJosephus::printAll() {
	list<Person>::iterator it = this->circ.begin();
	while(it != this->circ.end()){
		it->print();
		cout << ", ";
		it++;
	}
	cout << endl;
}

int ListMyJosephus::getN() {
	return this->N;
}

int ListMyJosephus::getM() {
	return this->M;
}

list<Person>::iterator ListMyJosephus::getBeginning() {
	return this->circ.begin();
}

list<Person>::iterator ListMyJosephus::getEnd() {
	return this->circ.end();
}