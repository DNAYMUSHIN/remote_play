#include "sender.h"
#include "protocol.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
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

int main(int argc, char* argv[]) {

    if (argc >= 2 && std::string(argv[1]) == "sender") {
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);

        Sender sender("192.168.1.105", PORT);

        std::cout << "Use arrow keys. ESC to exit.\n";

        while (true) {
            int key = _getch();

            if (key == 27) break; // ESC

            if (key == 224) {
                key = _getch();
                switch (key) {
                case 72:
                    sender.sendPacket(Direction::UP);
                    printf("UP!\n");
                    break;
                case 80:
                    sender.sendPacket(Direction::DOWN);
                    printf("DOWN!\n");
                    break;
                case 75:
                    sender.sendPacket(Direction::LEFT);
                    printf("LEFT!\n");
                    break;
                case 77:
                    sender.sendPacket(Direction::RIGHT);
                    printf("RIGHT!\n");
                    break;
                }
            }
        }
    }
    else {
        Square square;
        screen(square);
    }
}

