#include "Character.h"

/* Constructor */
Character::Character (int x, int y, int HP, int atk, int def) : Component(x, y) {
	maxHP = HP;
	maxAtk = atk;	
	maxDef = def;

	curHP = HP;
	curAtk = atk;
	curDef = def;
}

/* return Character's current HP/Attack/Defense */
int Character::getHP() {
	return curHP;
}
int Character::getAtk() {
	return curAtk;
}
int Character::getDef() {
	return curDef;
}

/* set Character's current HP/Attack/Defense */
void Character::setHP(int HP) {
	curHP = HP;
}
void Character::setAtk(int atk) {
	curAtk = atk;
}
void Character::setDef(int def) {
	curDef = def;
}

/* reset the value of Attack/Defense as beginning (step on another floor) */
void Character::resetAtk() {
	curAtk = maxAtk;
}
void Character::resetDef() {
	curDef = maxDef;
}

/* Desturctor */
Character::~Character() {}
