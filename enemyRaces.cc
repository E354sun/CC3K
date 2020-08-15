#include <cmath>
#include "playerRaces.h"
#include "enemyRaces.h"
#include "definitions.h"
#include "Treasure.h"
using namespace std;

// ============= Human
Human::Human(int x, int y): Enemy(x, y, HUMAN_HP, HUMAN_ATK, HUMAN_DEF) {}

string Human::getRace() {
	return HUMAN_RACE;
}

void Human::getAttacked(Shade *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Human::getAttacked(Drow *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Human::getAttacked(Vampire *p) {		// vampire's gifted talent
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	p->setHP(p->getHP() + 5);
}
void Human::getAttacked(Troll *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Human::getAttacked(Goblin *p) {		// stole 5 gold from slain enemies
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	if (getHP() <= 0) {
		p->pickupGold(5);
	}
}

void Human::Attack(Player *p) {
	p->getAttacked(this);
}

Human::~Human() {}

// ================ Dwarf
Dwarf::Dwarf(int x, int y): Enemy(x, y, DWARF_HP, DWARF_ATK, DWARF_DEF) {}

string Dwarf::getRace() {
	return DWARF_RACE;
}

void Dwarf::getAttacked(Shade *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Dwarf::getAttacked(Drow *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Dwarf::getAttacked(Vampire *p) {		// allergic reaction
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	p->setHP(p->getHP() - 5); 
}
void Dwarf::getAttacked(Troll *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Dwarf::getAttacked(Goblin *p) {		// stole 5 gold from slain enemies
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	if (getHP() <= 0) {
		p->pickupGold(5);
	}
}

void Dwarf::Attack(Player *p) {
	p->getAttacked(this);
}

Dwarf::~Dwarf() {}

// ================ Halfling
Halfling::Halfling(int x, int y): Enemy(x, y, HALFLING_HP, HALFLING_ATK, HALFLING_DEF) {}

string Halfling::getRace() {
	return HALFLING_RACE;
}

void Halfling::getAttacked(Shade *p) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	}
}
void Halfling::getAttacked(Drow *p) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	}
}
void Halfling::getAttacked(Vampire *p) {		// allergic reaction
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
		p->setHP(p->getHP() + 5); 
	}
}
void Halfling::getAttacked(Troll *p) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	}
}
void Halfling::getAttacked(Goblin *p) {		// stole 5 gold from slain enemies
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
		if (getHP() <= 0) {
			p->pickupGold(5);
		}
	}
}

void Halfling::Attack(Player *p) {
	p->getAttacked(this);
}

Halfling::~Halfling() {}

// ============= Orc
Orc::Orc(int x, int y): Enemy(x, y, ORC_HP, ORC_ATK, ORC_DEF) {}

string Orc::getRace() {
	return ORC_RACE;
}

void Orc::getAttacked(Shade *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Orc::getAttacked(Drow *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Orc::getAttacked(Vampire *p) {		// vampire's gifted talent
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	p->setHP(p->getHP() + 5);
}
void Orc::getAttacked(Troll *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Orc::getAttacked(Goblin *p) {		// stole 5 gold from slain enemies
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	if (getHP() <= 0) {
		p->pickupGold(5);
	}
}

void Orc::Attack(Player *p) {
	p->getAttacked(this);
}

Orc::~Orc() {}

// ============= Elf
Elf::Elf(int x, int y): Enemy(x, y, ELF_HP, ELF_ATK, ELF_DEF) {}

string Elf::getRace() {
	return ELF_RACE;
}

void Elf::getAttacked(Shade *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Elf::getAttacked(Drow *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Elf::getAttacked(Vampire *p) {		// vampire's gifted talent
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	p->setHP(p->getHP() + 5);
}
void Elf::getAttacked(Troll *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Elf::getAttacked(Goblin *p) {		// stole 5 gold from slain enemies
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	if (getHP() <= 0) {
		p->pickupGold(5);
	}
}

void Elf::Attack(Player *p) {
	p->getAttacked(this);
}

Elf::~Elf() {}

// ============= Merchant
extern bool hostileMerchant;		// set as false at first

Merchant::Merchant(int x, int y): Enemy(x, y, MERCHANT_HP, MERCHANT_ATK, MERCHANT_DEF) {}

string Merchant::getRace() {
	return MERCHANT_RACE;
}

void Merchant::getHostile() {
	hostileMerchant = true;
}

void Merchant::getAttacked(Shade *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	getHostile();
}
void Merchant::getAttacked(Drow *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	getHostile();
}
void Merchant::getAttacked(Vampire *p) {		// vampire's gifted talent
	getHostile();
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	p->setHP(p->getHP() + 5);
}
void Merchant::getAttacked(Troll *p) {
	getHostile();
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Merchant::getAttacked(Goblin *p) {		// stole 5 gold from slain enemies
	getHostile();
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	if (getHP() <= 0) {
		p->pickupGold(5);
	}
}

void Merchant::Attack(Player *p) {
	p->getAttacked(this);
}

Merchant::~Merchant() {}

// ================ Dragon

Dragon::Dragon(int x, int y, Gold *hoard): 
	Enemy(x, y, DRAGON_HP, DRAGON_ATK, DRAGON_DEF){}

	//Enemy(x, y, DRAGON_HP, DRAGON_ATK, DRAGON_DEF), hoard(hoard) {}

string Dragon::getRace() {
	return DRAGON_RACE;
}

void Dragon::getAttacked(Shade *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Dragon::getAttacked(Drow *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Dragon::getAttacked(Vampire *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	p->setHP(p->getHP() + 5);
}
void Dragon::getAttacked(Troll *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
}
void Dragon::getAttacked(Goblin *p) {
	setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)p->getAtk()));
	if (getHP() <= 0) {
		p->pickupGold(5);
	}
}
void Dragon::Attack(Player *p) {
	p->getAttacked(this);
}
void Dragon::spawnHoard() {
	hoard->releaseGuard();
}

Dragon::~Dragon() {}

