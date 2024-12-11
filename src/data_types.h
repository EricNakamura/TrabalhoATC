struct int2d {
    int x;
    int y;

    // Adicionando operador de atribuição
    int2d& operator=(const int2d& other) {
        if (this != &other) {
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
    }
};