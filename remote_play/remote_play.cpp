#include "sender.h"
#include "protocol.h"
#include <conio.h>
#include <iostream>
#include <windows.h>

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
        // часть друга — он сюда допишет свой Qt код
    }

    return 0;
}