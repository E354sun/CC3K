#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Character.h"

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Player;

class Enemy : public Character {
private:
	Enemy(int x, int y, int HP, int atk, int def);

	virtual void getAttacked(Shade sp) = 0;
	virtual void getAttacked(Drow *p) = 0;
	virtual void getAttacked(Vampire *p) = 0;
	virtual void getAttacked(Troll *p) = 0;
	virtual void getAttacked(Goblin *p) = 0;

	virtual void Attack(Player *p) = 0;

	~Enemy();
};

#endif