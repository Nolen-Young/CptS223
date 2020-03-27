#include "VectorMyJosephus.h"

VectorMyJosephus::VectorMyJosephus() {
	this->size = 0;
	this->N = 0;
	this->M = 0;
}

VectorMyJosephus::VectorMyJosephus(int N, int M) {
	this->N = N;
	this->size = N;
	this->M = M;
	Person newPerson;
	// creates Persons and gives them position i
	for (int i = 0; i < N; i++) {
		newPerson.setPosition(i);
		this->circ.push_back(newPerson);
	}
}

VectorMyJosephus::~VectorMyJosephus() {
	this->circ.clear();
}

void VectorMyJosephus::init(int N, int M) {
	this->N = N;
	this->size = N;
	this->M = M;
	Person newPerson;
	// creates Persons and gives them position i 
	for (int i = 0; i < N; i++) {
		newPerson.setPosition(i);
		this->circ.push_back(newPerson);
	}
}

void VectorMyJosephus::clear() {
	this->circ.clear();
	size = 0;
}

int VectorMyJosephus::currentSize() {
	return this->size;
}

bool VectorMyJosephus::isEmpty() {
	return this->circ.empty();
}

Person VectorMyJosephus::eliminateNext(vector<Person>::iterator temp) {
	Person yo;
	yo = *temp;
	this->size--;
	temp = circ.erase(temp);
	return yo;
}

void VectorMyJosephus::printAll() {
	vector<Person>::iterator it = this->circ.begin();
	while (it != this->circ.end()) {
		it->print();
		cout << ", ";
		it++;
	}
	cout << endl;
}

int VectorMyJosephus::getN() {
	return this->N;
}

int VectorMyJosephus::getM() {
	return this->M;
}

vector<Person>::iterator VectorMyJosephus::getBeginning() {
	return this->circ.begin();
}

vector<Person>::iterator VectorMyJosephus::getEnd() {
	return this->circ.end();
}

int VectorMyJosephus::getPosition(vector<Person>::iterator it) {
	return it->getPosition();
}

void VectorMyJosephus::run() {
	vector<Person> elims;
	int it_pos = 0;

	vector<Person>::iterator it = this->circ.begin(), temp;

	while (this->size > 1) {
		for (int i = this->M; i > 0; i--) {
			if (it_pos == --this->size) {
				it = this->circ.begin();
				it_pos = 0;
			}
			else {
				it++;
				it_pos++;
			}
		}
		// stores the eliminated people into a queue for later printing
		temp = it;
		if (it_pos == --this->size) {
			it = this->circ.begin();
			it_pos = 0;
		}
		else {
			it++;
			it_pos++;
		}
		elims.push_back(this->eliminateNext(temp));
		//print statistics
		this->printAll();
	}
	// print eliminated list and then the winner on one line
	cout << "{ ";
	vector<Person>::iterator it2 = elims.begin();
	it_pos = 0;
	do {
		it2->print();
		cout << ", ";
		it2++;
		it_pos++;
	} while (it_pos != elims.size() - 1);
	cout << " } Winner: ";
	this->printAll();
}
