#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Character.h"

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Player;

class Enemy : public Character {
public:
	Enemy(int x, int y, int HP, int atk, int def);

	virtual void getAttacked(Shade *p) = 0;
	virtual void getAttacked(Drow *p) = 0;
	virtual void getAttacked(Vampire *p) = 0;
	virtual void getAttacked(Troll *p) = 0;
	virtual void getAttacked(Goblin *p) = 0;

	virtual void Attack(Player *p) = 0;

	virtual ~Enemy();
};

#endif
