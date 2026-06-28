// remote_play.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "visual.h"

void screen(Square dot) {
    printf("-------\n");
    for (int i = 0; i < 5; ++i)
    {
        char temp[8];
        temp[0] = '|';
        temp[6] = '|';
        temp[7] = '\0';

        for (int j = 0; j < 5; ++j)
        {
            if (dot.getX() == j && dot.getY() == i)
                temp[j + 1] = '0';  // Сдвиг на 1, чтобы не затирать temp[0]
            else
                temp[j + 1] = ' ';  // Сдвиг на 1
        }
        printf("%s\n", temp);
    }
    printf("-------\n");
}

int main()
{
    Square square;
    screen(square);

}
