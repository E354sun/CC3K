#ifndef __STATE_H__
#define __STATE_H__
#include <cstdlib>
#include "Component.h"
#include "Map.h"
#include "Enemy.h"
#include "Player.h"

class Engine {
public:
	static bool move(Map *map, Player *player, int x, int y);
	static void moveRandom(Map *map, Enemy *enemy);
	static bool move(Map *map, Enemy *enemy, int x, int y);
};

class State {
private:
	Map *map;
	Player *player;
public:
	State(Map *map, Player *player);
	~State();

	void update();
};

 #endif