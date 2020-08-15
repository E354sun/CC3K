#include "Map.h"
#include <utility>
#include <vector>
using namespace std;

extern int stairR; //row value of the staircase to next level
extern int stairC; //column value of the staircase to next level
extern int floorNum;
extern int numOfE; //number of Enemies


Map::Map() {
	floor = new Tile**[25];
	for (int i=0; i<25; i++) {
		floor[i] = new Tile*[79];
	}

	for (int i=0; i<25; i++) {
		for (int j=0; j<79; j++) {
			floor[i][j] = NULL;
		}
	}

}

void Map::loadMap() {
	// allocate spaces for each chamber
	chamber = new Tile**[5];

	// load map information from map.txt
	ifstream mapFile ("map.txt");
	int numLines = 0;
	while (numLines < 25) {
		string line;
		getline(mapFile, line);

		int n = line.length();
		char components[n+1];
		strcpy(components, line.c_str());
		for (int i=0; i<79; ++ i) {
			floor[numLines][i] = new Tile(numLines, i, components[i]);
			cout << floor[numLines][i]->getItem();
		}

		cout << endl;
		numLines += 1;
	}
    
    // Components inside each chamber
	chamber[0] = new Tile *[26*4];
	for (int i=0; i<4; i++) {
		for (int j=0; j<26; j++) {
			chamber[0][(26*i)+j] = floor[i+3][j+3];
		}
	}

	chamber[1] = new Tile *[21*7];
	for (int i=0; i<7; i++) {
		for (int j=0; j<21; j++) {
			chamber[1][(21*i)+j] = floor[i+15][j+4];
		}
	}

	chamber[2] = new Tile *[15*8+9*9]; 
	numLines = 0;
	while (numLines < 10) {
		if (numLines < 2) {
			for (int j=0; j<23; j++) {
				chamber[2][(numLines*23)+j] = floor[numLines+3][j+39];
			}
		} else if (numLines == 2) {
			for (int j=0; j<31; j++) {
				chamber[2][(numLines*23)+j] = floor[numLines+3][j+39];
			}
		} else if (numLines == 3) {
			for (int j=0; j<34; j++) {
				chamber[2][(numLines*23)+8+j] = floor[numLines+3][j+39];
			}
		} else {
			for (int j=0; j<15; j++) {
				chamber[2][(numLines*15)+16+19+16+j] = floor[numLines+3][j+61];
			}
		}

		numLines += 1;
	}

	chamber[3] = new Tile *[12*6];
	for (int i=0; i<3; i++) {
		for (int j=0; j<12; j++) {
			chamber[3][(12*i)+j] = floor[i+10][j+38];
		}
	} 


	chamber[4] = new Tile *[39*3+11*3]; 
	for (int i=0; i<3; i++) {
		for (int j=0; j<11; j++) {
			chamber[4][(11*i)+j] = floor[i+16][j+65];
		}
		for (int j=0; j<39; j++) {
			chamber[4][11*3+(39*i)+j] = floor[i+19][j+37];
		}
	}
}

bool Map::isTaken(int x, int y) {
	if (floor[x][y]->getComponent() != NULL) {
		return true;
	} 

	return false;
}

Component *Map::getComponent(int x, int y) {
	return floor[x][y]->getComponent();
}

void Map::setComponent(Component *c, int x, int y) {
	floor[x][y]->setComponent(c);
}

void Map::displayMap() {
	for (int i=0; i<25; ++i) {
		for (int j=0; j<79; ++j) {
			if (!isTaken(i, j)) {
				if (i != stairR || j != stairC) {
					cout << floor[i][j]->getItem();
				} else {
					cout << "\\";
				}
			}
			else {
				Component *item = getComponent(i,j);
				string race = item->getRace();
				if (race == "Potion") {
					cout << "P";
				} else if (race == "Gold") {
					cout << "G";
				} else if (race == "Human") {
					cout << "H";
				} else if (race == "Dwarf") {
					cout << "W";
				} else if (race == "Halfling") {
					cout << "L";
				} else if (race == "Elf") {
					cout << "E";
				} else if (race == "Orc") {
					cout << "O";
				} else if (race == "Merchant") {
					cout << "M";
				// } else if (race == "Dragon") {
				//	cout << "D";
				} else {
					cout << "@";
				}
			}
		}
		cout << endl;
	}
	
}

void Map::spawnItem(int x, int y, Component *c) {
	floor[x][y]->setComponent(c);
}

void Map::spawnItem(Tile *t, Component *c) {
	t->setComponent(c);
}

void Map::removeItem(int x, int y) {
	if (isTaken(x, y)) {
		floor[x][y]->setComponent(NULL); 
	}
}

void Map::spawnItemRandom(Component *c) {
	const int numTile[5] = {104, 147, 201, 36, 150};

	// random pick a Tile
	int randChamber = rand()%5;
	int randTile = rand()%numTile[randChamber];
	int x = chamber[randChamber][randTile]->getXpos();
	int y = chamber[randChamber][randTile]->getYpos();

	while (isTaken(x, y)) {
		randChamber = rand()%5;
		randTile = rand()%numTile[randChamber];
		x = chamber[randChamber][randTile]->getXpos();
		y = chamber[randChamber][randTile]->getYpos();
	}

	if (!isTaken(x, y)) {
		spawnItem(x, y, c); 
		c->setXpos(x); 
		c->setYpos(y);
	} else {
		cout << "All chambers are full!" << endl;
	}

    
    Gold *hoard = dynamic_cast<Gold*>(c);

    if (hoard && hoard->getAmount() == 6) {
    	vector<pair<int, int>> Tiles;
    	Tiles.push_back(make_pair(-1, -1));
    	Tiles.push_back(make_pair(-1, 1));
    	Tiles.push_back(make_pair(-1, 0));
    	Tiles.push_back(make_pair(1, -1));
    	Tiles.push_back(make_pair(1, 1));
    	Tiles.push_back(make_pair(1, 0));
    	Tiles.push_back(make_pair(0, -1));
    	Tiles.push_back(make_pair(0, 1));

    	int randInt;
    	int randX;
    	int randY;

    	// what if all 8 connected ceils are full?

    	do {
    		randInt = rand()%8;
    		randX = x + Tiles.at(randInt).first;
    		randY = y + Tiles.at(randInt).second;
    	} while (isTaken(randX, randY) || 
    					floor[randX][randY]->isTaken());

    	Dragon *d = new Dragon(randX, randY, hoard);
    	spawnItem(randX, randY, d);
    	hoard->setGuard(d);

    	numOfE --;
    }

}

void Map::start(Player *hero) {
	// srand(time(NULL));
	const int numTile[5] = {104, 147, 201, 36, 150};

	int randChamber = rand()%5;
	int randTile = rand()%numTile[randChamber];
	int playerXpos = chamber[randChamber][randTile]->getXpos();
	int playerYpos = chamber[randChamber][randTile]->getYpos();

	spawnItem(playerXpos, playerYpos, hero);	// player

	hero->setXpos(playerXpos);
	hero->setYpos(playerYpos);

	int randChamberS = rand()%5;				// stairs
	while (randChamberS == randChamber) {
		randChamberS = rand()%5;
	}
	randTile = rand()%numTile[randChamberS];
	stairR = chamber[randChamberS][randTile]->getXpos();
	stairC = chamber[randChamberS][randTile]->getYpos();

	for (int i=0; i<10; i++) {					// potion
		int randPotion = rand()%6;
		string type;

		switch(randPotion) {
			case 0 : type = "RH";
					 break;
			case 1 : type = "BA";
					 break;
			case 2 : type = "BD";
					 break;
			case 3 : type = "PH";
					 break;
			case 4 : type = "WA";
					 break;
			case 5 : type = "WD";
					 break;
			default: cout << "Potion Spawning Failed!" << endl;
					 break;
		}

		Potion *potion = new Potion(1, 1, type);
		spawnItemRandom(potion);
	}

	for (int i=0; i<10; i++) {				// Hoard
		int randGold = rand()%8;
		int amount;

		if (randGold < 2) {
			amount = 1;
		} else if (randGold == 2) {
			amount = 6;
		} else {
			amount = 2;
		}

		Gold *treasure = new Gold(1, 1, amount);
		spawnItemRandom(treasure);
	}
	
    for (int i=0; i<numOfE; i++) {			// Enemy
		int randEnemy = rand()%18;
		Enemy *e;

		if (randEnemy < 4) {
			e = new Human(0, 0);
		} else if (randEnemy < 7) {
			e = new Dwarf(0, 0);
		} else if (randEnemy < 12) {
			e = new Halfling(0, 0);
		} else if (randEnemy < 14) {
			e = new Elf(0, 0);
		} else if (randEnemy < 16) {
			e = new Orc(0, 0);
		} else {
			e = new Merchant(0, 0); 
		}

		spawnItemRandom(e);
	}

}

//Destructor
Map::~Map() {
	for (int i=0; i<25; i++) {
		delete [] floor[i];
	}
	delete [] floor;
}

// ====================== Display Status
Status::Status(Map *map, Player *player): map(map), player(player) {}

void Status::update() {
	Race = player->getRace();
	HP = player->getHP();
	Atk = player->getAtk();
	Def = player->getDef();
	Gold = player->getGold();
}

void Status::display() {
	update();
	map->displayMap();
	cout << "Race: " << Race;
	cout << "  Gold: " << Gold << endl;
	cout << "HP: " << HP << endl;
	cout << "Atk: " << Atk << endl;
	cout << "Def: " << Def << endl;
	cout << "Action: " << endl;
}
