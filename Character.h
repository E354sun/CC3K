#ifndef _CHARACTER_H_
#define _CHARACTER_H_
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

	/* move the Character (change Character's position) */
	void setPos(int x, int y);
	int getXpos();
	int getYpos();

	/* Desturctor */
	virtual ~Character();
};

#endif