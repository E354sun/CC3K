#include "Player.h"

Player::Player(int x, int y, int HP, int atk, int def): Character(x, y, HP, atk, def) {
	gold = 0;
}

void Player::pickupGold(int amount) {
	gold += amount;
}

int Player::getGold() {
	return gold;
}

Player::~Player() {}