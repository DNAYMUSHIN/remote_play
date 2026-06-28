// Square.cpp
#include "visual.h"
#include "protocol.h"

// Реализация конструкторов
Square::Square() : x(0), y(0) {}


// Геттеры
float Square::getX() const { return x; }
float Square::getY() const { return y; }

// Сеттеры
void Square::setX(float x) { this->x = x; }
void Square::setY(float y) { this->y = y; }

// Дополнительные методы
void Square::moveup() {
	y++;
}

void Square::movedown() {
	y--;
}

void Square::moveright() {
	x++;
}

void Square::moveleft() {
	x--;
}

void Square::getmove(Direction dir){ 
	switch (dir)
	{
	case Direction::UP: moveup();
		break;
	case Direction::DOWN: movedown();
		break;
	case Direction::RIGHT: moveright();
		break;
	case Direction::LEFT: moveleft();
		break;
	}


}