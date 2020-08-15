#include <iostream>
#include <sstream>
#include <string>
#include "Map.h"
#include "Component.h"
#include "Items.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "playerRaces.h"
#include "enemyRaces.h"
#include "Treasure.h"
#include "State.h"
using namespace std;

string command;
bool start = true;
bool hostileMerchant = false;
int floorNum;
int stairR;
int stairC;

enum dirCode {
    no,
    so,
    ea,
    we,
    ne,
    nw,
    se,
    sw
};

dirCode hashit (string const& inString) {
    if (inString == "no") return no;
    if (inString == "so") return so;
    if (inString == "ea") return ea;
    if (inString == "we") return we;
    if (inString == "ne") return ne;
    if (inString == "nw") return nw;
    if (inString == "se") return se;
    if (inString == "sw") return sw;
}

enum raceCode {
    S,
    D,
    V,
    T,
    G,
    Q
};

raceCode hashRace (string const& inString) {
    if (inString == "S") return S;
    if (inString == "D") return D;
    if (inString == "V") return V;
    if (inString == "T") return T;
    if (inString == "G") return G;
    if (inString == "Q") return Q;
}

int numOfE = 20; 
bool gameOn = true;
bool dead = false;
bool quit = false;

int main() {
	while (start) {

		Player *hero;
		start = true;
		hostileMerchant = false;

		cout << "Welcome to the game of ChamberCrawler3000" << endl;
		cout << "Please choose the race of your hero:" << endl;
		cout << "(S)hade: 125 HP, 25 Atk, 25 Def" << endl;
    	cout << "(D)row: 150 HP, 25 Atk, 15 Def, Potion Talent" << endl;
    	cout << "(V)ampire: 50 HP, 25 Atk, 25 Def, Gain HP by Successful Attacks" << endl;
    	cout << "(T)roll: 120 HP, 25 Atk, 15 Def, Gain HP Every Single Turn" << endl;
    	cout << "(G)oblin: 110 HP, 15 Atk, 20 Def, Clever Thieves" << endl;
    	cout << "Please enter the one you like, or enter Q to leave" << endl;

    	bool inputValid = false;
    	while (!inputValid) {
    		cin >> command;

    		switch (hashRace(command)) {
    			case S: cout << "Your hero is a Shade now!" << endl;
    					  hero = new Shade(5, 5);
    					  inputValid = true;
    					  break;
    			case D: cout << "Your hero is a Drow now!" << endl;
    					  hero = new Drow(5, 5);
    					  inputValid = true;
    					  break;
    			case V: cout << "Your hero is a Vampire now!" << endl;
    					  hero = new Vampire(5, 5);
    					  inputValid = true;
    					  break;
    			case T: cout << "Your hero is a Troll now!" << endl;
    					  hero = new Troll(5, 5);
    					  inputValid = true;
    					  break;
    			case G: cout << "Your hero is a Goblin now!" << endl;
    					  hero = new Troll(5, 5);
    					  inputValid = true;
    					  break;
    			case Q: cout << "Thank you!" << endl;
    					  start = false;
    					  break;
    			default:  cout << "Oops, it seems that you have chosen a mysterious race" << endl;
      					  cout << "Sorry, would you like to rechoose your hero?" << endl;
      					  break;
    		}
    	}

    	if (!start) {
    		break;
    	}

    	Map *map = new Map();
    	map->loadMap();

    	Status *statusBar = new Status(map, hero);
    	State *state = new State(map, hero);

    	while (floorNum <= 5) {
    		map->start(hero);
    		statusBar->display();

    		while (gameOn) {
    			cin >> command;

    			int playerXpos = hero->getXpos();
    			int playerYpos = hero->getYpos();

    			switch (hashit(command)) {
    				case no: Engine::move(map, hero, playerXpos-1, playerYpos);
    						   break;
    				case so: Engine::move(map, hero, playerXpos+1, playerYpos);
    						   break;
    				case ea: Engine::move(map, hero, playerXpos, playerYpos+1);
    						   break;
    				case we: Engine::move(map, hero, playerXpos, playerYpos-1);
    						   break;
    				case ne: Engine::move(map, hero, playerXpos-1, playerYpos+1);
    						   break;
    				case nw: Engine::move(map, hero, playerXpos-1, playerYpos-1);
    						   break;
    				case se: Engine::move(map, hero, playerXpos+1, playerYpos+1);
    						   break;
    				case sw: Engine::move(map, hero, playerXpos+1, playerYpos-1);
    						   break;
    				default:   break;
    			}

    			if (command == "u") {
    				cin >> command;
    				switch (hashit(command)) {
    					case no: 
    						if (map->isTaken(playerXpos-1, playerYpos)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos-1, playerYpos));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos-1, playerYpos);
    							}
    						}
    						break;
    					case so: 
    						if (map->isTaken(playerXpos+1, playerYpos)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos+1, playerYpos));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos+1, playerYpos);
    							}
    						}
    						break;
    					case ea: 
    						if (map->isTaken(playerXpos, playerYpos+1)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos, playerYpos+1));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos, playerYpos+1);
    							}
    						}
    						break;
    					case we: 
    						if (map->isTaken(playerXpos, playerYpos-1)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos, playerYpos-1));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos, playerYpos-1);
    							}
    						}
    						break;
    					case ne: 
    						if (map->isTaken(playerXpos-1, playerYpos+1)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos-1, playerYpos+1));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos-1, playerYpos+1);
    							}
    						}
    						break;
    					case nw: 
    						if (map->isTaken(playerXpos-1, playerYpos-1)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos-1, playerYpos-1));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos-1, playerYpos-1);
    							}
    						}
    						break;
    					case se: 
    						if (map->isTaken(playerXpos+1, playerYpos+1)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos+1, playerYpos+1));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos+1, playerYpos+1);
    							}
    						}
    						break;
    					case sw: 
    						if (map->isTaken(playerXpos+1, playerYpos-1)) {
    							Potion *potion;
    							potion = dynamic_cast<Potion *> (map->getComponent(playerXpos+1, playerYpos-1));
    							if (potion) {
    								potion->takePotion(hero);
    								map->removeItem(playerXpos+1, playerYpos-1);
    							}
    						}
    						break;
    					default:   break;
    				}
    			}

    			else if (command == "a") {
    				cin >> command;

    				switch (hashit(command)) {
    					case no: 
    						if (map->isTaken(playerXpos-1, playerYpos)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos-1, playerYpos));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case so: 
    						if (map->isTaken(playerXpos+1, playerYpos)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos+1, playerYpos));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case ea: 
    						if (map->isTaken(playerXpos, playerYpos+1)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos, playerYpos+1));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case we: 
    						if (map->isTaken(playerXpos, playerYpos-1)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos, playerYpos-1));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case ne: 
    						if (map->isTaken(playerXpos-1, playerYpos+1)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos-1, playerYpos+1));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case nw: 
    						if (map->isTaken(playerXpos-1, playerYpos-1)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos-1, playerYpos-1));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case se: 
    						if (map->isTaken(playerXpos+1, playerYpos+1)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos+1, playerYpos+1));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					case sw: 
    						if (map->isTaken(playerXpos+1, playerYpos-1)) {
    							Enemy *enemy;
    							enemy = dynamic_cast<Enemy *> (map->getComponent(playerXpos+1, playerYpos-1));
    							if (enemy) {
    								hero->Attack(enemy);
    							}
    						}
    						break;
    					default:   break;
    				}
    			}

    			else if (command == "r") {
    				cout << "You restart the advanture!" << endl;
					gameOn = false;
					quit = true;
					break;
    			}

    			else if (command == "q") {
    				cout << "Thank you and goodbye!" << endl;
					gameOn = false;
					start = false;
					quit = true;
					break;
    			}

    			else {
    				cout << "Oops, I cannot recognize your command!" << endl;
    			}

    			state->update();
    			statusBar->display();

    			if (dead) {
    				cout << "Your hero has died..." << endl;
    				gameOn = false;
    				break;
    			}

    			if (hero->getXpos() == stairR && hero->getYpos() == stairC) {
    				map->removeItem(stairR, stairC);
    				break;
    			}

    			Troll *t = dynamic_cast<Troll *>(hero);
    			if (t) {
    				t->Regain();
    			}
    		}

    		hero->resetAtk();
    		hero->resetDef();

    		for (int x=0; x<25; ++ x) {
    			for (int y=0; y<79; ++ y) {
    				Component *c = map->getComponent(x, y);
    				map->removeItem(x, y);
    				delete c;
    			}
    		}

    		if (dead || quit) {
    			break;
    		}

    		floorNum ++;
    		cout << endl;
    	}

    	if (floorNum > 5) {
    		cout << "Congratulations, you won!" << endl;
		}

		
		if (quit == false) {
			cout << "Would you like to play again?" << endl;
			cout << "Please Enter (Y)es or (N)o:" << endl;

			cin >> command;

			if (command == "Y") {
				cout << "Welcome back!" << endl;
			} else if (command == "N") {
				cout << "Thank you!" << endl;
				start = false;
				break;
			} else {
				cout << "Please enter Y or N" << endl;
			}
		}

	}
}
