#include "Items.h"

// ================== Potion
Potion::Potion(int x, int y, string type): Component(x, y), Type(type) {
	if (type == "RH") {	//Restore health
		HP = 10;
		Atk = 0;
		Def = 0;
	} else if (type == "BA") {	// Boost Atk
		HP = 0;
		Atk = 5;
		Def = 0;
	} else if (type == "BD") {	// Boost Def
		HP = 0;
		Atk = 0;
		Def = 5;
	} else if (type == "PH") {	// Poison health
		HP = -10;
		Atk = 0;
		Def = 0;
	} else if (type == "WA") {	// Wound Atk
		HP = 0;
		Atk = -5;
		Def = 0;
	} else if (type == "WD") {	// Wound Def
		HP = 0;
		Atk = 0;
		Def = -5;
	}
}

int Potion::getHP() {
	return HP;
}
int Potion::getAtk() {
	return Atk;
}
int Potion::getDef() {
	return Def;
}

string Potion::getRace() {
	return "Potion";
}
string Potion::getType() {
	return Type;
}

void Potion::takePotion(Player *p) {
	if (p->getRace() != "Drow") {
		p->setHP(p->getHP() + HP);
		p->setAtk(p->getAtk() + Atk);
		p->setDef(p->getDef() + Def);
	} else {
		p->setHP(p->getHP() + 1.5*HP);
		p->setAtk(p->getAtk() + 1.5*Atk);
		p->setDef(p->getDef() + 1.5*Def);
	}
}

Potion::~Potion() {}


// ================= Tile
Tile::Tile(int x, int y, char item): xPos(x), yPos(y), item(item) {
	component = NULL;
}

int Tile::getXpos() {
	return xPos;
}
int Tile::getYpos() {
	return yPos;
}
Component *Tile::getComponent() {
	return component;
}
void Tile::setComponent(Component *c) {
	component = c;
}
char Tile::getItem() {
	return item;
}

bool Tile::isSteppable() {
	if (item != '.' && item != '+' && item != '#') {
		return false;
	} else {
		return true;
	}
}

bool Tile::isTaken() {
	if (item != '.') {
		return false;
	} else {
		return true;
	}
}

Tile::~Tile() {}
