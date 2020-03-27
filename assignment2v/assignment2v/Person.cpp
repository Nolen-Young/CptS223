#include "Person.h"

Person::Person() {
	
}

Person::~Person(){
	
}

void Person::print(){
	std::cout << this->position;
}

void Person::setPosition(int n){
	this->position = n;
}

int Person::getPosition()
{
	return this->position;
}
