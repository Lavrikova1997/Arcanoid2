#pragma once
#include <SFML\Graphics.hpp>
#include "func.h"

using namespace sf;

typedef struct strBall
{
	CircleShape *sprite;
	float radius = 5.f;
	float speed = 0.1f;
	Vector2f dir = Vector2f(-0.71f, 0.71f);
	unsigned int attack = 1;
	bool inBoard = true;
}Ball;

void iniBall(Ball &ball, Vector2f pos);
void moveGorBall(Ball& ball, float time, float speed);
void moveSprite(Ball & ball, float time);
void wallCollision(Ball & ball, Vector2u windowSize);
void reflectionBoard(Ball &ball);
void ReflectionBelow(Ball& ball, float time);
void ReflectionAbove(Ball& ball, float time);
void ReflectionLeft(Ball& ball, float time);
void ReflectionRigth(Ball& ball, float time);

