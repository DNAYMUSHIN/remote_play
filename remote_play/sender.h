// sender.h
#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "protocol.h"  // ← добавь это

class Sender {
public:
    Sender(const std::string& ip, int port);
    ~Sender();
    void sendPacket(Direction dir);

private:
    SOCKET sock;  // ← и это исправь, int → SOCKET
    struct sockaddr_in receiver_addr;
};