#include "EngineBall.h"

void MoveBallInBoard(Ball & ball, Board & board, float time)
{
	if (board.dir == LEFT)
	{
		moveGorBall(ball, time, -(board.speed));
		ball.dir = Vector2f(-0.71f, -0.71f);
	}
	else if (board.dir == RIGHT)
	{
		moveGorBall(ball, time, board.speed);
		ball.dir = Vector2f(0.71f, -0.71f);
	};
};

void CollisionAndMove(Ball & ball, list<Brick*> & bricks, Board & board, float time, Vector2u windowSize)
{
	wallCollision(ball, windowSize);

	if (ball.sprite->getGlobalBounds().intersects(board.sprite->getGlobalBounds()))
	{
		reflectionBoard(ball);
	};

	for (Brick *pBrick : bricks)
	{
		if (ball.sprite->getGlobalBounds().intersects(pBrick->sprite->getGlobalBounds()))
		{
			Vector2f posBall = ball.sprite->getPosition();
			Vector2f posBrick = pBrick->sprite->getPosition();
			if ((posBall.y > posBrick.y) && (ball.dir.y < 0.f))
			{
				ReflectionBelow(ball, time);
				DamageBrick(pBrick, ball.attack);
			}
			else if ((posBall.x < posBrick.x) && (ball.dir.x > 0.f))
			{
				ReflectionLeft(ball, time);
				DamageBrick(pBrick, ball.attack);
			}
			else if ((posBall.x > posBrick.x) && (ball.dir.x < 0.f))
			{
				ReflectionRigth(ball, time);
				DamageBrick(pBrick, ball.attack);
			}
			else if ((posBall.y < posBrick.y) && (ball.dir.y > 0.f))
			{
				ReflectionAbove(ball, time);
				DamageBrick(pBrick, ball.attack);
			}
		};
	}

	moveSprite(ball, time);
}

void iniGameObj(Board & board, Ball & ball, list<Brick*> & bricks, Vector2u windowSize)
{
	iniBoard(board, Vector2f(100.0f, 5.f), Vector2f(windowSize.x / 2.f - 50, windowSize.y - 50.f));
	iniBall(ball, Vector2f(windowSize.x / 2.f, windowSize.y - 60.f));
	iniList(bricks);
}

void DispolseGameObj(Board * board, Ball * ball, list<Brick*> & bricks)
{
	DeleteList(bricks);
}