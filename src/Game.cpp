#include "Game.h"

Game::Game()
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

void Game::addRegion(const RenderRegion* region)
{
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