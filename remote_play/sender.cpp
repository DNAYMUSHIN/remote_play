#include "sender.h"
#include "protocol.h"
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

Sender::Sender(const std::string& ip, int port) {
    // Инициализация Winsock (обязательно на Windows)
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &receiver_addr.sin_addr);
}

Sender::~Sender() {
    closesocket(sock);
    WSACleanup();
}

void Sender::sendPacket(Direction dir) {
    Packet pkt;
    pkt.dir = dir;
    sendto(sock, (char*)&pkt, sizeof(pkt), 0,
        (sockaddr*)&receiver_addr, sizeof(receiver_addr));
}