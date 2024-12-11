#include "RenderRegion.h"
#include <exception>
#include <iostream>
#include <Windows.h>
#include <string>

void RenderRegion::initWindow()
{
	window = newwin(dimensions.y, dimensions.x, position.y, position.x);
	wclear(window);
	wrefresh(window);
}

RenderRegion::RenderRegion() : dimensions({10,10}), position({0,0})
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

bool RenderRegion::resize_Term()
{
	wresize(window, dimensions.y , dimensions.x);
	Update();
	return true;
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
	std::string posStr = "Position: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")\n";
	OutputDebugStringA(posStr.c_str());
	return position;
}
void RenderRegion::Clear()
{
	wclear(window);
	wrefresh(window);
}

void RenderRegion::Center()
{
	Clear();
	int boardX, boardY;
	getmaxyx(stdscr, boardY, boardX);
	position = { (boardX / 2) - (dimensions.x / 2), (boardY / 2) - (dimensions.y/2) };
	mvwin(window, position.y, position.x);
}

void RenderRegion::Centered()
{
	center = true;
}

void RenderRegion::Update()
{
	if (center)
	{
		Center();
	}
	draw();
	wrefresh(window);
}

void RenderRegion::draw()
{
}
