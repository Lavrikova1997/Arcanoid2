#include "strBrick.h"

Brick* iniBrick(Vector2f pos, unsigned dur)
{
	Brick* brick;
	brick = new Brick;
	brick->sprite = new RectangleShape;

	brick->durability = dur;
	brick->sprite->setPosition(pos);
	brick->sprite->setOutlineColor(Color(10, 10, 10));
	brick->sprite->setOutlineThickness(1.f);
	brick->sprite->setSize(Vector2f(WIGTH, HEIGTH));

	return  brick;
}

void DamageBrick(Brick *brick, unsigned int atck)
{
	if (brick->durability < atck)
	{
		brick->durability = 0;
	}
	else
	{
		brick->durability -= atck;
	}
}

