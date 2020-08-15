#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "Component.h"

class Character : public Component {
protected:
	/* Character's maximum HP/Attack/Defense */
	int maxHP; 
	int maxAtk; 	
	int maxDef;

	/* Character's current HP/Attack/Defense */
	int curHP;
	int curAtk;
	int curDef;

public:
	/* Constructor */
	Character(int x, int y, int HP, int atk, int def);

	/* return Character's current HP/Attack/Defense */
	int getHP();
	int getAtk();
	int getDef();

	/* set Character's current HP/Attack/Defense */
	void setHP(int HP);
	void setAtk(int atk);
	void setDef(int def);

	/* reset the value of Attack/Defense as beginning (step on another floor) */
	void resetAtk();
	void resetDef();

	/* Desturctor */
	virtual ~Character();
};

#endif
