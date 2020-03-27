#include "VectorMyJosephus.h"

int main(void) {
	int n_people = 0,
		m_passes = 0;


	//get variables from user
	cout << "Enter number of people in game: ";
	cin >> n_people;
	cout << "Enter number of passes before elimination: ";
	cin >> m_passes;
	//initialize list

	VectorMyJosephus thaList(n_people, m_passes);

	cout << "Running game..." << endl;
	thaList.run();

	//simulation loop
	

}