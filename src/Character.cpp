#include "Character.h"
#include <curses.h>

Character::Character(int2d pos, char symbol, int color)
    : pos(pos), sprite(symbol), colorPair(color) {}

void Character::draw() {
    attron(COLOR_PAIR(colorPair));
    mvaddch(pos.y, pos.x, sprite);
    attroff(COLOR_PAIR(colorPair));
}

void Character::move(int dx, int dy) {
    pos.x += dx;
    pos.y += dy;
}

int Character::getX() const {
    return pos.x;
}

int Character::getY() const {
    return pos.y;
}

void Character::updateState() {
}

float Distance(const Character* sh1,const Character* sh2 ) {
    float distX = std::fabs(sh1->getX() - sh2->getX());
    float distY = std::fabs( sh1->getY() - sh2->getY() );
    float dist = std::hypot(distX,distY);
    return dist;
}

float Distance( int2d* pos1, int2d* pos2 ) {
    float distX = std::fabs( pos1->x - pos2->x );
    float distY = std::fabs( pos1->y - pos2->y  );
    float dist = std::hypot( distX, distY );
    return dist;
}