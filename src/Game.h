#pragma once
#include <list>
#include "RenderRegion.h"
#include "PacMan.h"
#include "UIManager.h"
#include "Ghost.h"
#include "PowerPellet.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Stop();
	void addRegion(const RenderRegion* region);
	bool update();
	void initGame();

private:
	bool running = false;
	Map map;
	UIManager ui;
	PacMan pacman;
	std::list<Ghost> ghosts;
	std::list<PowerPellet> powerPellets;
	unsigned int score;
	unsigned int lives;
	bool victory;


};


