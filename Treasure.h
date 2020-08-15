#ifndef __TREASURE_H__
#define __TREASURE_H__
#include <string>
#include "Component.h"
#include "enemyRaces.h"

class Gold : public Component {
private:
	int amount;
	bool Guarded;

	Dragon *guard;

public:
	Gold(int x, int y, int gold);
	string getRace();
	int getAmount();

	
	bool isGuarded();
	void releaseGuard();
	Dragon *getGuard();
	void setGuard(Dragon *dragon);
	

	virtual ~Gold();
};

#endif