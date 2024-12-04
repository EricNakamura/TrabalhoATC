#pragma once
#include <curses.h>
#include "data_types.h"

class RenderRegion
{
private:
	WINDOW* window;
	int2d dimensions;
	int2d position;
	bool center;

	void initWindow();
	void Center();

public:
	RenderRegion();
	RenderRegion(int2d dimensions, int2d position);
	virtual ~RenderRegion();
	bool resize_Term();
	bool SetDimensions(int2d dimensions);
	bool SetPosition(int2d position);
	bool SetWindow(WINDOW* window);
	bool SetWindow(int2d dimensions, int2d position);
	WINDOW* GetWindow();
	int2d GetDimensions();
	int2d GetPosition();
	void Clear();
	void Centered();
	virtual void Update();
	virtual void Draw();
	
	 
};

