#include "listBricks.h"

void iniList(list< Brick* > & bricks)
{
	float i = 50;
	const unsigned int DURABILITY = 4;
	const unsigned int DIST_BWN_CNTRS_BRCK_Y = 50;
	const unsigned int DIST_BWN_CNTRS_BRCK_X = 100;
	while (i < 400)
	{
		float g = 100;
		while (g < 650)
		{
			bricks.push_back(iniBrick(Vector2f(g, i), DURABILITY));
			g += DIST_BWN_CNTRS_BRCK_X;
		};
		i += DIST_BWN_CNTRS_BRCK_Y;
	};
}

void RenderList(list<Brick*> & bricks, RenderWindow & window)
{
	list<Brick*>::iterator it;
	for (it = bricks.begin(); it != bricks.end(); it++)
	{
		switch ((*it)->durability)
		{
		case 1:
			(*it)->sprite->setFillColor(Color(255, 0, 0));
			break;
		case 2:
			(*it)->sprite->setFillColor(Color(0, 255, 0));
			break;
		case 3:
			(*it)->sprite->setFillColor(Color(0, 0, 255));
			break;
		default:
			(*it)->sprite->setFillColor(Color(150, 150, 150));
		}
		window.draw(*((*it)->sprite));
	};
}

void UpdateList(list<Brick*> & bricks)
{
	list<Brick*>::iterator it;
	it = bricks.begin();
	while (it != bricks.end())
	{
		if ((*it)->durability == 0)
		{
			delete(*it);
			it = bricks.erase(it);
		}
		else {
			it++;
		};
	};
}

void DeleteList(list<Brick*> & bricks)
{
	list<Brick*>::iterator it;
	it = bricks.begin();
	while (it != bricks.end())
	{
		delete(*it);
		it = bricks.erase(it);
	};
}