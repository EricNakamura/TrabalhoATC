#include <vector>
#include <string>
#include "RenderRegion.h"


class Map : public RenderRegion {
private:
    std::vector<std::string> layout; // Representação do labirinto

public:
    
    Map();// Construtor
    void loadMap(const std::string& filename);// Carrega o labirinto de um arquivo   
    void draw(); // Desenha o labirinto na tela   
    char getTile(int x, int y) const;// Retorna o caractere em uma posição específica  
    void setTile(int x, int y, char newTile);// Atualiza o caractere em uma posição específica  
    bool isWalkable(int x, int y) const;// Verifica se uma posição é válida para o movimento   
    int countDots() const;// Retorna o número de pontos restantes no labirinto   
};

