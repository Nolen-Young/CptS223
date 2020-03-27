#include "Player.h"

Player::Player(int nid, int nx, int ny) {
	this->id = nid;
	this->x = nx;
	this->y = ny;
}

int Player::getX() {
	return this->x;
}

int Player::getY() {
	return this->y;
}

void Player::setX(int x) {
	this->x = x;
}

void Player::setY(int y) {
	this->y = y;
}
