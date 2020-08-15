#include "State.h"
#include "enemyRaces.h"
#include "Items.h"
#include <utility>
#include <vector>
using namespace std;

extern bool hostileMerchant;

bool Engine::move(Map *map, Player *player, int x, int y) {
	if (!map->floor[x][y]->isSteppable()) {
		return false;
	} else if (map->isTaken(x, y)) {
		if (map->getComponent(x, y)->getRace() == "Gold") {
			Gold *g = dynamic_cast<Gold *> (map->getComponent(x, y));
			if (g->isGuarded()) {
				return false;
			} else {
				player->pickupGold(g->getAmount());
			}
		} else {
			return false;
		}
	}

	map->removeItem(player->getXpos(), player->getYpos());
	map->spawnItem(x, y, player);
	player->setXpos(x);
	player->setYpos(y);

	return true;
}

void Engine::moveRandom(Map *map, Enemy *enemy) {
	int randInt;
	vector<pair<int, int>> Tiles;
	Tiles.push_back(make_pair(-1, -1));
    Tiles.push_back(make_pair(-1, 1));
    Tiles.push_back(make_pair(-1, 0));
    Tiles.push_back(make_pair(1, -1));
    Tiles.push_back(make_pair(1, 1));
    Tiles.push_back(make_pair(1, 0));
    Tiles.push_back(make_pair(0, -1));
    Tiles.push_back(make_pair(0, 1));
    int x = enemy->getXpos();
    int y = enemy->getYpos();

    while (randInt = rand()%9) {
    	if (randInt < 8) {
    		int randX = x + Tiles.at(randInt).first;
    		int randY = y + Tiles.at(randInt).second;
    		if (move(map, enemy, randX, randY)) {
    			break;
    		}
    	} else {
    		break;
    	}
    }
}

bool Engine::move(Map *map, Enemy *enemy, int x, int y) {
	if (map->floor[x][y]->isTaken() || map->isTaken(x, y)) {
		return false;
	} else {
		map->removeItem(enemy->getXpos(), enemy->getYpos());
		map->spawnItem(x, y, enemy);
		enemy->setXpos(x);
		enemy->setYpos(y);
		return true;
	}
}

State::State(Map *map, Player *player): map(map), player(player) {}


void State::update() {
	extern bool isDead;

	for (int x=0; x<25; x++) {
		for (int y=0; y<79; y++) {
			if (map->isTaken(x, y)) {
				Enemy *enemy;
				enemy = dynamic_cast<Enemy*>(map->getComponent(x, y));
				if (enemy) {
					string race = enemy->getRace();
					if (enemy->getHP() <= 0) {
						if (race == "Dragon") {
							Dragon *dragon = dynamic_cast<Dragon*> (enemy);
							dragon->spawnHoard();
						} else if (race == "Human" || race == "Merchant") {
							player->pickupGold(4);
						} else {
							int randInt = rand()%100;
							if (randInt < 50) {
								player->pickupGold(2);
							} else {
								player->pickupGold(1);
							}
						}
						map->removeItem(x, y);
						delete enemy;
						return;
					}

					if (race == "Merchant" && !hostileMerchant) {
						Engine::moveRandom(map, enemy);
					} else {
						// (race == "Merchant" && hostileMerchant) || race != "Merchant")
						vector<pair<int, int>> Tiles;
						Tiles.push_back(make_pair(-1, -1));
    					Tiles.push_back(make_pair(-1, 1));
    					Tiles.push_back(make_pair(-1, 0));
    					Tiles.push_back(make_pair(1, -1));
    					Tiles.push_back(make_pair(1, 1));
    					Tiles.push_back(make_pair(1, 0));
    					Tiles.push_back(make_pair(0, -1));
    					Tiles.push_back(make_pair(0, 1));

    					int randX;
    					int randY;

    					for (int i=0; i<8; i++) {
    						randX = x + Tiles.at(i).first;
    						randY = y + Tiles.at(i).second;
    						if (map->isTaken(randX, randY) 
    							&& map->getComponent(randX, randY) == player) {
    							enemy->Attack(player);
    							break;
    						} else if (i == 7 && enemy->getRace() != "Dragon") {
    							Engine::moveRandom(map, enemy);
    						}
    					}
					}
				}	

				Gold *gold;
				gold = dynamic_cast<Gold *>(map->getComponent(x, y));
				if (gold) {
					if (gold->isGuarded() == true) {
						vector<pair<int, int>> Tiles;
						Tiles.push_back(make_pair(-1, -1));
    					Tiles.push_back(make_pair(-1, 1));
    					Tiles.push_back(make_pair(-1, 0));
    					Tiles.push_back(make_pair(1, -1));
    					Tiles.push_back(make_pair(1, 1));
    					Tiles.push_back(make_pair(1, 0));
    					Tiles.push_back(make_pair(0, -1));
    					Tiles.push_back(make_pair(0, 1));

    					int randX;
    					int randY;

    					for (int i=0; i<8; i++) {
    						randX = x + Tiles.at(i).first;
    						randY = y + Tiles.at(i).second;
    						if (map->isTaken(randX, randY) 
    							&& map->getComponent(randX, randY) == player) {
    							gold->getGuard()->Attack(player);
    							break;
    						}
    					}
    				}
    			}
    		}
    	}
	}

	if (player->getHP() <= 0) {
		isDead = true;
		return;
	}
}
