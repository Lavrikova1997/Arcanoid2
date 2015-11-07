#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

const float WIGTH = 100;
const float HEIGTH = 50;

typedef struct strBrick
{
	unsigned int durability = 1;
	RectangleShape * sprite;
} Brick;

Brick* iniBrick(Vector2f pos, unsigned dur);
void DamageBrick(Brick *brick, unsigned int atck);

