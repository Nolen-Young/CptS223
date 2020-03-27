#include "Player.h"
#include <iostream>
#include <map>

class Board {
private:
	int m;
	std::map<int, Player> players; //the int is going to be the player's id
	bool findIdMatch(int sid); //returns true if there is another player with that id *this could also be seen as the find function specified in the project*
	int findCoordMatch(int x, int y); // returns the id of the other player if there is another player at those coordinates
	bool remove(int rid); // removes player with id 'rid'
public:
	//constructor
	Board(int im);
	bool Insert(int id, int x, int y); // creates a new player with id 'id' at coordinates 'x' and 'y'
	bool MoveTo(int id, int x, int y); //moves player with id 'id' to coordinate at 'x' and 'y'
	void PrintByID(); //prints all players in the game by id
};
