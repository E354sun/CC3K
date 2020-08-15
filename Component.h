#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include <iostream>
#include <string>
using namespace std;

class Component {
private:
	int xPos;
	int yPos;
public:
	Component(int x, int y);
	virtual string getRace() = 0;

	int getXpos();
	int getYpos();
	void setXpos(int x);
	void setYpos(int y);

	virtual ~Component();
};


#endif
