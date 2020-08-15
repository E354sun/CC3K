Component::Component(int x, int y): xPos(x), yPos(y) {}

int Component::getXpos() {
	return xPos;
}
int Component::getYpos() {
	return yPos;
}
void Component::setXpos(int x) {
	xPos = x;
}
void Component::setYpos(int y) {
	yPos = y;
}