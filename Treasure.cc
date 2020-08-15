#include "Treasure.h"

// ================= Gold
Gold::Gold(int x, int y, int gold): Component(x, y) {
	amount = gold;
	guard = NULL;

	if (amount != 6) {	// is a hoard guarded by a dragon
		Guarded = false;
	} else {
		Guarded = true;
	}
}

string Gold::getRace() {
	return "Gold";
}

int Gold::getAmount() {
	return amount;
}

bool Gold::isGuarded() {
	return Guarded;
}
void Gold::releaseGuard() {
	Guarded = false;
}
Dragon *Gold::getGuard() {
	return guard;
}
void Gold::setGuard(Dragon *dragon) {
	guard = dragon;
}

Gold::~Gold() {}