#ifndef _ENEMYRACES_H_
#define _ENEMYRACES_H_
#include "Enemy.h"
#include "Player.h"
#include <string>
using namespace std;

class Human : public Enemy {
public:
	Human(int x, int y);
	string getRace();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);

	~Human();
};

class Dwarf : public Enemy {
public:
	Dwarf(int x, int y);
	string getRace();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);

	~Dwarf();
};

class Halfling : public Enemy {
public:
	Halfling(int x, int y);
	string getRace();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);

	~Halfling();
};

class Elf : public Enemy {
public:
	Elf(int x, int y);
	string getRace();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);

	~Elf();
};

class Orc : public Enemy {
public:
	Orc(int x, int y);
	string getRace();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);

	~Orc();
};


class Merchant : public Enemy {
public:
	Merchant(int x, int y);
	string getRace();
	void getHostile();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);

	~Merchant();
};


class Gold;

class Dragon : public Enemy {
private:
	Gold *hoard;
public:
	Dragon(int x, int y, Gold *hoard);
	string getRace();

	void getAttacked(Shade *p);
	void getAttacked(Drow *p);
	void getAttacked(Vampire *p);
	void getAttacked(Troll *p);
	void getAttacked(Goblin *p);

	void Attack(Player *p);
	void spawnHoard();

	~Dragon();
};


#endif