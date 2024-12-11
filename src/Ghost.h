#include "Character.h"
#include <cstdlib> // Necess�rio para rand
#include <curses.h>
#include "PacMan.h"



enum GhostState { NORMAL, VULNERABLE }; // Estados poss�veis do fantasma

class Ghost : public Character {
    
private:
    unsigned int color;

    GhostState state; // Estado atual do fantasma
    int vulnerableTimer; // Tempo restante no estado vulner�vel

    bool defeated;

public:
    // Construtor
    Ghost(int2d pos, char symbol, int color);
    Ghost( );

    
    // M�todos espec�ficos do fantasma
    void setState(GhostState newState, int duration = 0); // Altera o estado do fantasma
    GhostState getState() const;                         // Retorna o estado atual
    void updateState() override;                                  // Atualiza o estado (ex.: decrementa o timer)
    void moveAutomatically(const PacMan* pacman, const Map& map);
    void draw();
    bool isDefeated() const;
    void setDefeated(bool state);

};