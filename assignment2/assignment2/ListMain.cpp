#include "ListMyJosephus.h"

int main(void) {
	int n_people = 0,
		m_passes = 0;
	list<Person> elims;

	//get variables from user
	cout << "Enter number of people in game: ";
	cin >> n_people;
	cout << "Enter number of passes before elimination: ";
	cin >> m_passes;
	//initialize list

	ListMyJosephus thaList(n_people, m_passes);
	list<Person>::iterator it = thaList.getBeginning(), temp;

	cout << "Running game..." << endl;
	clock_t start = clock();
	//simulation loop
	while(thaList.currentSize() > 1) {
		for(int i = thaList.getM(); i > 0; i--) {
			if(it == --thaList.getEnd()){
				it = thaList.getBeginning();
			}
			else {
				it++;
			}
		}
		// stores the eliminated people into a queue for later printing
		temp = it;
		if (it == --thaList.getEnd()) {
			it = thaList.getBeginning();
		}
		else {
			it++;
		}
		elims.push_back(thaList.eliminateNext(temp));
		//print statistics
		//thaList.printAll();
	}
	// print eliminated list and then the winner on one line
	/*cout << "{ ";
	list<Person>::iterator it2 = elims.begin();
	do{
		it2->print();
		cout << ", ";
		it2++;
	} while (it2 != elims.end());*/
	clock_t end = clock();
	cout << " } Winner: ";
	thaList.printAll();
	cout << "CPU elapsed time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

}
