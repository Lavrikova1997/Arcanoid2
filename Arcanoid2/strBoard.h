#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

typedef enum boardDir 
{
	NONE,
	LEFT,
	RIGHT
} Direct;

typedef struct strBoard
{
	RectangleShape * sprite;
	Direct dir = NONE;
	float speed = 0.2f;
	float width = 0;
} Board;

void iniBoard(Board & board, Vector2f size, Vector2f pos);
void update(Board & board, float time, Vector2u windowSize);
