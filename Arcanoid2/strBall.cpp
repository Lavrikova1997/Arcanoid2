#include "strBall.h"

void iniBall(Ball &ball, Vector2f pos)
{
	ball.sprite = new CircleShape();
	ball.sprite->setRadius(ball.radius);
	ball.sprite->setPosition(pos.x, pos.y);
	ball.sprite->setFillColor(Color(255, 255, 150));
}

void moveGorBall(Ball& ball, float time, float speed)
{
	ball.sprite->move(time*speed, 0);
}

void moveSprite(Ball & ball, float time)
{
	ball.sprite->move(ball.speed*time*(ball.dir.x), ball.speed*time*(ball.dir.y));
}

void wallCollision(Ball & ball, Vector2u windowSize)
{
	Vector2f pos = ball.sprite->getPosition();
	if ((pos.x + ball.radius) > windowSize.x)
	{
		ball.dir.x = neg(ball.dir.x);
	}
	else if ((pos.x - ball.radius) < 0.f)
	{
		ball.dir.x = poz(ball.dir.x);
	}
	else if ((pos.y + ball.radius) > windowSize.y)
	{
		ball.dir.y = neg(ball.dir.y);
	}
	else if ((pos.y - ball.radius) < 0.f)
	{
		ball.dir.y = poz(ball.dir.y);
	};
}

void reflectionBoard(Ball &ball)
{
	ball.dir.y = neg(ball.dir.y);
}

void ReflectionBelow(Ball& ball, float time)
{
	ball.dir.y = poz(ball.dir.y);
	moveSprite(ball, time);
}
void ReflectionAbove(Ball& ball, float time)
{
	ball.dir.y = neg(ball.dir.y);
	moveSprite(ball, time);
}
void ReflectionLeft(Ball& ball, float time)
{
	ball.dir.x = neg(ball.dir.x);
	moveSprite(ball, time);
}
void ReflectionRigth(Ball& ball, float time)
{
	ball.dir.x = poz(ball.dir.x);
	moveSprite(ball, time);
}
