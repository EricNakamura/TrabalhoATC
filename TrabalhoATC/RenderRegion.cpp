#include "RenderRegion.h"

void RenderRegion::initWindow()
{
	window = newwin(dimensions.y, dimensions.x, position.y, position.x);
	wrefresh(window);
	
}

RenderRegion::RenderRegion() : dimensions({0,0}), position({0,0})
{
	initWindow();
}

RenderRegion::RenderRegion(int2d dimensions, int2d position) : dimensions(dimensions), position(position)
{
	initWindow();
}

RenderRegion::~RenderRegion()
{
}

bool RenderRegion::SetDimensions(int2d dimensions)
{
	return false;
}

bool RenderRegion::SetPosition(int2d position)
{
	return false;
}

bool RenderRegion::SetWindow(WINDOW* window)
{
	return false;
}

bool RenderRegion::SetWindow(int2d dimensions, int2d position)
{
	return false;
}

WINDOW* RenderRegion::GetWindow()
{
	return nullptr;
}

int2d RenderRegion::GetDimensions()
{
	return int2d();
}

int2d RenderRegion::GetPosition()
{
	return int2d();
}

void RenderRegion::Clear()
{
}

void RenderRegion::Update()
{
	wclear(window);
	clear();
	for (int c = 0; c < COLS; c++) {
		for (int l = 0; l < LINES; l++) {
			mvwprintw(stdscr, c, l, "X");
		}
	}
	wrefresh(window);
	refresh();
}
