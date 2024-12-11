#pragma once
#include <cmath>
#include "data_types.h"

class Character {
protected:
    int2d pos;          // Posição do personagem
    char sprite;       // Representação visual
    int colorPair;     // Cor do personagem

public:
    Character(int2d pos, char symbol, int color);
    Character() = default;

    virtual void draw();
    virtual void move(int dx, int dy);

    virtual int getX() const;
    virtual int getY() const;

    friend float Distance(const Character* sh1,const Character* sh2);
    friend float Distance( int2d* pos1, int2d* pos2 );

    virtual void updateState();
    
    virtual ~Character() = default; // Defina um destrutor virtual para evitar problemas
};

