#ifndef __MAP_H__
#define __MAP_H__
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Enemy.h"
#include "Items.h"
#include "Treasure.h"
#include "enemyRaces.h"

using namespace std;

class Map {
public:
	Tile ***floor;		// floor map
	Tile ***chamber;	// room
	Map();
	void loadMap();
	void displayMap();

	bool isTaken(int x, int y);
	Component *getComponent(int x, int y);
	void setComponent(Component *c, int x, int y);

	void spawnItem(int x, int y, Component *c);
	void removeItem(int x, int y);
	void spawnItem(Tile *t, Component *c);
	void spawnItemRandom(Component *c);

	void start(Player *hero);
	~Map();
};

class Status {
private:
	Player *player;
	Map *map;
	string Race;
	int Gold;
	int HP;
	int Atk;
	int Def;
public:
	Status(Map *map, Player *player);
	void update();
	void display();
};

#endif
