#include <cmath>
#include "playerRaces.h"
#include "enemyRaces.h"
#include "definitions.h"
using namespace std;

/* =========== Player races =========== */
// ============== Shade
Shade::Shade(int x, int y): Player(x, y, SHADE_HP, SHADE_ATK, SHADE_DEF) {}

string Shade::getRace() {
	return SHADE_RACE;
}

void Shade::getAttacked(Human *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Shade::getAttacked(Dwarf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Shade::getAttacked(Halfling *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Shade::getAttacked(Elf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 

	chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
}
void Shade::getAttacked(Orc *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Shade::getAttacked(Merchant *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Shade::getAttacked(Dragon *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}

void Shade::Attack(Enemy *e) {
	e->getAttacked(this);
}

Shade::~Shade() {}

// ============= Drow

Drow::Drow(int x, int y): Player(x, y, DROW_HP, DROW_ATK, DROW_DEF) {}

string Drow::getRace() {
	return DROW_RACE;
}

void Drow::getAttacked(Human *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Drow::getAttacked(Dwarf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Drow::getAttacked(Halfling *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Drow::getAttacked(Elf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
}
void Drow::getAttacked(Orc *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Drow::getAttacked(Merchant *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Drow::getAttacked(Dragon *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}

void Drow::Attack(Enemy *e) {
	e->getAttacked(this);
}

Drow::~Drow() {}

// ============= Vampire

Vampire::Vampire(int x, int y): Player(x, y, VAMPIRE_HP, VAMPIRE_ATK, VAMPIRE_DEF) {}

string Vampire::getRace() {
	return VAMPIRE_RACE;
}

void Vampire::getAttacked(Human *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Vampire::getAttacked(Dwarf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Vampire::getAttacked(Halfling *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Vampire::getAttacked(Elf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
	chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
}
void Vampire::getAttacked(Orc *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Vampire::getAttacked(Merchant *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Vampire::getAttacked(Dragon *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}

void Vampire::Attack(Enemy *e) {
	e->getAttacked(this);
}

Vampire::~Vampire() {}

// ============= Troll

Troll::Troll(int x, int y): Player(x, y, TROLL_HP, TROLL_ATK, TROLL_DEF) {}

string Troll::getRace() {
	return TROLL_RACE;
}

void Troll::getAttacked(Human *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Troll::getAttacked(Dwarf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Troll::getAttacked(Halfling *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Troll::getAttacked(Elf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
	chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
}
void Troll::getAttacked(Orc *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Troll::getAttacked(Merchant *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Troll::getAttacked(Dragon *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}

void Troll::Attack(Enemy *e) {
	e->getAttacked(this);
}
void Troll::Regain() {
	int HP = getHP() + 5;
	if (HP < TROLL_HP) {
		setHP(getHP() + 5);
	}
	
}

Troll::~Troll() {}

// ============= Goblin

Goblin::Goblin(int x, int y): Player(x, y, GOBLIN_HP, GOBLIN_ATK, GOBLIN_DEF) {}

string Goblin::getRace() {
	return GOBLIN_RACE;
}

void Goblin::getAttacked(Human *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Goblin::getAttacked(Dwarf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Goblin::getAttacked(Halfling *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Goblin::getAttacked(Elf *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
	chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	} 
}
void Goblin::getAttacked(Orc *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - 1.5 * ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Goblin::getAttacked(Merchant *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}
void Goblin::getAttacked(Dragon *e) {
	int chance = rand() % 100;
	if (chance < 50) {
		setHP(getHP() - ceil(100.0/(100.0+(double)getDef())*(double)e->getAtk()));
	}
}

void Goblin::Attack(Enemy *e) {
	e->getAttacked(this);
}

Goblin::~Goblin() {}

