#ifndef __PLAYERRACES_H__
#define __PLAYERRACES_H__
#include "Player.h"
#include "Enemy.h"
#include <string>
using namespace std;

class Shade : public Player {
public:
	Shade(int x, int y);
	string getRace();

	void getAttacked(Human *e);
	void getAttacked(Dwarf *e);
	void getAttacked(Halfling *e);
	void getAttacked(Elf *e);
	void getAttacked(Orc *e);
	void getAttacked(Merchant *e);
	void getAttacked(Dragon *e);

	void Attack(Enemy *e);

	~Shade();
};

class Drow : public Player {
public:
	Drow(int x, int y);
	string getRace();

	void getAttacked(Human *e);
	void getAttacked(Dwarf *e);
	void getAttacked(Halfling *e);
	void getAttacked(Elf *e);
	void getAttacked(Orc *e);
	void getAttacked(Merchant *e);
	void getAttacked(Dragon *e);

	void Attack(Enemy *e);

	~Drow();
};

class Vampire : public Player {
public:
	Vampire(int x, int y);
	string getRace();

	void getAttacked(Human *e);
	void getAttacked(Dwarf *e);
	void getAttacked(Halfling *e);
	void getAttacked(Elf *e);
	void getAttacked(Orc *e);
	void getAttacked(Merchant *e);
	void getAttacked(Dragon *e);

	void Attack(Enemy *e);

	~Vampire();
};

class Troll : public Player {
public:
	Troll(int x, int y);
	string getRace();

	void getAttacked(Human *e);
	void getAttacked(Dwarf *e);
	void getAttacked(Halfling *e);
	void getAttacked(Elf *e);
	void getAttacked(Orc *e);
	void getAttacked(Merchant *e);
	void getAttacked(Dragon *e);

	void Attack(Enemy *e);
	void Regain();

	~Troll();
};


class Goblin : public Player {
public:
	Goblin(int x, int y);
	string getRace();

	void getAttacked(Human *e);
	void getAttacked(Dwarf *e);
	void getAttacked(Halfling *e);
	void getAttacked(Elf *e);
	void getAttacked(Orc *e);
	void getAttacked(Merchant *e);
	void getAttacked(Dragon *e);

	void Attack(Enemy *e);

	~Goblin();
};

#endif
