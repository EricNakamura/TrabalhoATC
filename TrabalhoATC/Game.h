#pragma once
#include <list>
#include "RenderRegion.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Stop();
	void addRegion(const RenderRegion* region);
	bool removeRegion(const RenderRegion* region);
	bool update();
	void initGame();

private:
	bool running = false;
	std::list<RenderRegion> renderRegions;


};


