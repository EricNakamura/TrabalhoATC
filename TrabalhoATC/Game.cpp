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
	renderRegions.push_back(*region);
}

bool Game::removeRegion(const RenderRegion* region)
{
	/*for (RenderRegion& reg : renderRegions)
	{
		if (reg == *region)
		{
			renderRegions.remove(reg);
			return true;
		}
	}*/
	return false;
}

bool Game::update()
{
	if (!running)
	{
		return false;
	}
	for (auto& region : renderRegions)
	{
		region.Update();
	}
	return true;
}