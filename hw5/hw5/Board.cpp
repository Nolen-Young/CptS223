#include "Board.h"

bool Board::findIdMatch(int sid) {
	// counts number of players with id 'sid'. returns true if at least 1 player in that game has id 'sid'
	if (this->players.count(sid))
		return true;

	return false;
}

int Board::findCoordMatch(int x, int y) {
	// begin iterator
	std::map<int, Player>::iterator it = players.begin();
	// loop to end of list
	while (it != players.end()) {
		// if a player has the same coordinates as passed in return the id
		if (x == it->second.getX() && y == it->second.getY()) {
			return it->first;
		}
		it++;
	}
	return 0;
}

bool Board::remove(int rid) {
	// checks to see if there is a player with id 'rid'
	if (players.count(rid)) {
		// makes iterator pointing to the player with id 'rid' and deletes it
		std::map<int, Player>::iterator it = players.find(rid);
		players.erase(it);
		return true;
	}
	return false;
}

Board::Board(int im) {
	this->m = im;
}

bool Board::Insert(int id, int x, int y) {
	
	if (x <= m && y <= m) {// checks if inbounds
		if (!findIdMatch(id)) {// makes sure nobody else has the same id
			if (!findCoordMatch(x, y)) { // makes sure no player is at coordinate x,y
				// inserts player
				Player p(id, x, y);
				players.insert(std::pair<int, Player>(id, p));
				return true;
			}
			else {
				std::cout << "Error: player already exists at coordinate" << std::endl;
			}
		}
		else {
			std::cout << "Error: ID already exists" << std::endl;
		}
	}
	else {
		std::cout << "Error: out of bounds" << std::endl;
	}
	return false;
}

bool Board::MoveTo(int id, int x, int y) {
	int temp;
	std::map<int, Player>::iterator target = this->players.find(id);
	if (target != this->players.end()) {// checks to see if the player exists
		// checks to see if the movement is valid
		if ((x == target->second.getX() || y == target->second.getY() || std::abs(target->second.getX() - x) == std::abs(target->second.getY() - y))) {
			if (x <= this->m && y <= this->m) { // checks to make sure the move is in bounds
				temp = findCoordMatch(x, y);
				// removes player if we need to
				if (temp != 0) {
					std::cout << "Player removed: " << temp << std::endl;
					remove(temp);
				}
				// moves the player
				target->second.setX(x);
				target->second.setY(y);
				return true;
			}
			else {
				std::cout << "Error: out of bounds." << std::endl;
			}
		}
		else {
			std::cout << "Error: invalid movement." << std::endl;
		}
	}
	else {
		std::cout << "Error: target doesn't exits." << std::endl;
	}
	return false;
}

void Board::PrintByID() {
	std::map<int, Player>::iterator it = this->players.begin();
	// loops through and prints each id
	for (it; it != this->players.end(); it++) {
		std::cout << it->first << ", ";
	}
	std::cout << std::endl;
}
