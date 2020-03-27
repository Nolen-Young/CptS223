/*
 * Person:
 * This class encapsulates a person within the Josephus circle.
 */

#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>

using namespace std;


class Person {

	public: 
		// Constructor:
		// Note: A person object should be created only if there is a position available for that person to occupy. 
		//		And of course, no two people can occupy the same position, and 
		//		no person can occupy more than one position at any given time.
		// ...
		Person();

		// Destructor
		// ...
		~Person();

		// print the position
		void print();

		void setPosition(int n);

		int getPosition();

	private:
		int position;
};

#endif
