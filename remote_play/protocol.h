// protocol.h
#pragma once

enum class Direction { UP, DOWN, LEFT, RIGHT };

struct Packet {
    Direction dir;
};

const int PORT = 12345;