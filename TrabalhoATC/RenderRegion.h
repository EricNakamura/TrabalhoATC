#pragma once
#include <curses.h>
#include "data_types.h"

class RenderRegion
{
	WINDOW* window;
	int2d dimensions;
	int2d position;

private:
	void initWindow();

public:
	RenderRegion();
	RenderRegion(int2d dimensions, int2d position);
	~RenderRegion();
	bool SetDimensions(int2d dimensions);
	bool SetPosition(int2d position);
	bool SetWindow(WINDOW* window);
	bool SetWindow(int2d dimensions, int2d position);
	WINDOW* GetWindow();
	int2d GetDimensions();
	int2d GetPosition();
	void Clear();
	virtual void Update();
	
	

};

