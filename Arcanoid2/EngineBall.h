#pragma once
#include "strBoard.h"
#include "listBricks.h"
#include "strBall.h"

void MoveBallInBoard(Ball & ball, Board & board, float time);
void CollisionAndMove(Ball & ball, list<Brick*> & bricks, Board & board, float time, Vector2u windowSize);
void iniGameObj(Board & board, Ball & ball, list<Brick*> & bricks, Vector2u windowSize);
void DispolseGameObj(Board * board, Ball * ball, list<Brick*> & bricks);