#include "Game.h"

void Game::initGame() {
	map.loadMap("Map.txt");

}

Game::Game()
{
	initGame();
}

Game::Game( PacMan plr, unsigned int score, unsigned int lives ):
 pacman(plr), score(score), lives(lives)
{
}

Game::~Game()
{
}

void Game::Run()
{
	running = true;
}

void Game::Stop()
{
	running = false;
}


bool Game::update()
{
	if (!running)
	{
		return false;
	}
	map.Update();
	return true;
}
