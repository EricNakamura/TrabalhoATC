
#include "Character.h"
#include "Map.h"
#include <ctime> // Para temporizador
#include "curses.h"
#include "data_types.h"

class PacMan : public Character {
private:
    bool isInvulnerable; // Indica se Pac-Man est� invulner�vel
    int invulnerabilityTimer; // Tempo restante de invulnerabilidade
    time_t powerModeStartTime; // Armazena o tempo de ativa��o do modo Power
    int originalColor = attroff(COLOR_PAIR(1)); // cor original
    int powerColor = attron(COLOR_PAIR(3)); // cor do pac-Man qunado em power mode

    //-------------------------------------------

    int currentDirectionX = 0; // Dire��o atual em X
    int currentDirectionY = 0; // Dire��o atual em Y
    int queuedDirectionX = 0;  // Pr�xima dire��o desejada em X
    int queuedDirectionY = 0;  // Pr�xima dire��o desejada em Y

public:

    bool powerMode;
    // Construtor
    PacMan(int2d pos, char symbol, int color);
    PacMan();

    // M�todos espec�ficos de Pac-Man
    void setInvulnerable(bool state, int duration = 0); // Define o estado de invulnerabilidade
    bool getInvulnerable() const;                      // Retorna se est� invulner�vel
    void updateState();                                // Atualiza o estado (ex.: decrementa o timer)
    void move(int dx, int dy, const Map& map); // M�todo atualizado
    void activatePowerMode();
    void deactivetedPowerMode();
    void draw();
    void updateState(const Map& map);
    void queueDirection(int dx, int dy);
    int2d GetPos();
    
};


