#pragma once
#include <list>
#include "strBrick.h"

using namespace std;

void iniList(list< Brick* > & bricks);
void RenderList(list<Brick*> & bricks, RenderWindow & window);
void UpdateList(list<Brick*> & bricks);
void DeleteList(list<Brick*> & bricks);