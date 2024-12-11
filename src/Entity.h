#pragma once
#include "Sprite.h"
#include "Collider.h"

class Entity: public Sprite
{
	int2d position;
	Collider collider;
	std::string state;

public:
	Entity();
	Entity(int2d position, Collider collider, std::string state);
	~Entity();
	
	void SetPosition(int2d position);
	void SetCollider(Collider collider);
	void SetState(std::string state);
	int2d GetPosition();
	Collider GetCollider();
	std::string GetState();
	void Update();
};

