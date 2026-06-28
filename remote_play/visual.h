#pragma once
#include "protocol.h"


class Square {
private:
    float x, y;          // координаты левого верхнего угла

public:
    // Конструкторы
    Square();

    // Геттеры (получение данных)
    float getX() const;
    float getY() const;


    // Сеттеры (установка данных)
    void setX(float x);
    void setY(float y);

    // Дополнительные методы
    void moveup();
    void movedown();
    void moveright();
    void moveleft();
    void getmove(Direction dir);
};