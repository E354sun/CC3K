#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Character.h"

class Human;
class Dwarf;
class Halfling;
class Elf;
class Orc;
class Merchant;
class Dragon;

class Enemy;

class Player : public Character {
private:
	/* races: Shade(by default), Drow, Vampire, Troll, Goblin */
	int gold;

public:
	Player(int x, int y, int HP, int atk, int def);
	void pickupGold(int amount);
	int getGold();

	/* */
	virtual void getAttacked(Human *e) = 0;
	virtual void getAttacked(Dwarf *e) = 0;
	virtual void getAttacked(Halfling *e) = 0;
	virtual void getAttacked(Elf *e) = 0;
	virtual void getAttacked(Orc *e) = 0;
	virtual void getAttacked(Merchant *e) = 0;
	virtual void getAttacked(Dragon *e) = 0;

	virtual void Attack(Enemy *e) = 0;

	~Player();
};

#endif
