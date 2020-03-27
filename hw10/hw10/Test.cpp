#include <ctime>
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"

int main(void) {
	std::vector<std::string> DataArray;
	std::vector<std::string> QueryArray;
	std::ifstream infile;
	std::ifstream infile2;
	infile.open("OHenry.txt");
	string temp;

	int collisions = 0;

	while (!infile.eof()) {
		infile >> temp;
		DataArray.push_back(temp);
	}
	infile2.open("Queries.txt");
	while (!infile2.eof()) {
		infile2 >> temp;
		QueryArray.push_back(temp);
	}

	LinearHashTable<std::string> LinearHT;
	clock_t start = clock();
	for (int i = 0; i < 10377; i++) { 
		collisions += LinearHT.insert(DataArray[i]);
	}
	clock_t end = clock();
	cout << "Linear Hashing insert time in seconds: "
       <<(double)(end - start)/CLOCKS_PER_SEC <<endl;
	std::cout << "Linear Collisions: " << collisions << std::endl;

	collisions = 0;
	QuadraticHashTable<std::string> QuadraticHT;
	start = clock();
	for (int i = 0; i < 10377; i++) {
		collisions += QuadraticHT.insert(DataArray[i]);
	}
	end = clock();
	cout << "Quadratic Hashing insert time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;
	std::cout << "Quadratic Collisions: " << collisions << std::endl;

	collisions = 0;
	ChainingHashTable<std::string> ChainingHT;
	start = clock();
	for (int i = 0; i < 10377; i++) {
		collisions += QuadraticHT.insert(DataArray[i]);
	}
	end = clock();
	// there are no collisions in chaining functions
	cout << "Chaining Hashing insert time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;


	start = clock();
	for (int j = 0; j < 1500; j++) {
		LinearHT.contains(QueryArray[j]);
	}
	end = clock();
	cout << "Linear hashing search time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	for (int j = 0; j < 1500; j++) {
		QuadraticHT.contains(QueryArray[j]);
	}
	end = clock();
	cout << "Quadratic hashing search time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	for (int j = 0; j < 1500; j++) {
		ChainingHT.contains(QueryArray[j]);
	}
	end = clock();
	cout << "Chaining hashing search time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;
	
	// call function here
	
}