#ifndef __ITEMS_H__
#define __ITEMS_H__
#include "Component.h"
#include <cstddef>
#include "playerRaces.h"

class Potion : public Component {
private:
	int HP;
	int Atk;
	int Def;
	string Type;

public: 
	Potion(int x, int y, string type);
	int getHP();
	int getAtk();
	int getDef();

	string getRace();
	string getType();
	void takePotion(Player *p);

	~Potion();
};

class Tile {
private:
	int xPos;
	int yPos;
	Component *component;
	char item;
public:
	Tile(int x, int y, char item);

	int getXpos();
	int getYpos();
	Component *getComponent();
	void setComponent(Component *c);
	char getItem();

	bool isSteppable();
	bool isTaken();

	~Tile();
};


#endif
