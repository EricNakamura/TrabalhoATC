#include "Ghost.h"



Ghost::Ghost(int2d pos, char symbol, int color)
    : Character({pos.x, pos.y}, 'G', color), state(NORMAL), vulnerableTimer(0), defeated(false), color(3) {}

Ghost::Ghost(): Character( { 0,0 }, 'G', 3 ) {
    
    state = NORMAL;
    vulnerableTimer = 0;
    defeated = false;
}



void Ghost::setState(GhostState newState, int duration) {
    state = newState;
    vulnerableTimer = duration;
}

GhostState Ghost::getState() const {
    return state;
}

// Implementa��o do m�todo updateState() para atualizar o estado do fantasma
void Ghost::updateState() {
    if (state == VULNERABLE && vulnerableTimer > 0) {
        --vulnerableTimer;
        if (vulnerableTimer == 0) {
            state = NORMAL; // Volta ao estado normal quando o tempo acaba
        }
    }
}

void Ghost::moveAutomatically(const PacMan* pacman, const Map& map) {
    // Dire��es poss�veis: cima, baixo, esquerda, direita
    int dx[] = { 0, 0, -1, 1 };  // Dire��es em X
    int dy[] = { -1, 1, 0, 0 };  // Dire��es em Y

    int melhorX = getX();
    int melhorY = getY();
    int menorDistancia = Distance(pacman, this);

    // Testar todas as 4 dire��es poss�veis (cima, baixo, esquerda, direita)
    for (int i = 0; i < 4; ++i) {
        int2d novoPos = {getX() + dx[i], getY() + dy[i] };

        // Verifica se a posi��o � v�lida (caminh�vel) e dentro dos limites do mapa
        if (map.isWalkable(novoX, novoY)) {
            // Verificar se outro fantasma est� a ocupar a posi��o
            bool ocupadoPorOutroFantasma = false;
            for (const auto& outroGhost : ghosts) {
                if (outroGhost.getX() == novoX && outroGhost.getY() == novoY) {
                    ocupadoPorOutroFantasma = true;
                    break;
                }
            }

            // Ignorar a posi��o se j� estiver ocupada
            if (ocupadoPorOutroFantasma) {
                continue;
            }

            // Calcular a dist�ncia at� o PacMan
            int distancia = 

            int distancia = std::abs(pacman.getX() - novoX) + std::abs(pacman.getY() - novoY);

            // Escolhe a dire��o mais pr�xima ao PacMan
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                melhorX = novoX;
                melhorY = novoY;
            }
        }
    }

    // Atualiza a posi��o do fantasma
    x = melhorX;
    y = melhorY;
}

void Ghost:: draw() {

    attron(COLOR_PAIR(color)); // Aplica a cor
    mvaddch(y, x, sprite);     // Desenha o fantasma na posi��o (x, y)
    attroff(COLOR_PAIR(color)); // Desativa a cor
}

bool Ghost::isDefeated() const {
    return defeated;  // A vari�vel 'defeated' indica se o fantasma foi derrotado
}

void Ghost::setDefeated(bool state) { 
    defeated = state; 
}

