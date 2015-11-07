#include "strBoard.h"

void iniBoard(Board & board, Vector2f size, Vector2f pos)
{
	board.sprite = new RectangleShape;
	board.sprite->setSize(size);
	board.width = size.x;
	board.sprite->setPosition(pos);
	board.sprite->setFillColor(Color(128, 0, 255));
}
void update(Board & board, float time, Vector2u windowSize)
{
	Vector2f pos = board.sprite->getPosition();
	if ((board.dir == LEFT) && (pos.x <= 0))
	{
		board.dir = NONE;
	}
	else if (board.dir == RIGHT && pos.x + board.width >= windowSize.x)
	{
		board.dir = NONE;
	};
	switch (board.dir)
	{
	case LEFT:
		board.sprite->move(-(board.speed)*time, 0);
		break;
	case RIGHT:
		board.sprite->move(+(board.speed)*time, 0);
		break;
	default:
		break;
	}
};