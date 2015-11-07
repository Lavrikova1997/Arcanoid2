#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "EngineBall.h"
#include "Menu.h"

using namespace sf;
using namespace std;

const Vector2u WINDOW_SIZE = Vector2u(800, 600);
const float COEF_SPEED_GAME = 400.f;

void GameProcess(RenderWindow & window, Font & font, bool &isWin, bool &isLose)
{
	Clock clock;
	Board board;
	Ball ball;
	list<Brick*> bricks;
	iniGameObj(board, ball, bricks, WINDOW_SIZE);
	Event event;
	bool isPause = false;
    
	while (window.isOpen() && (!isWin) && (!isLose))
	{   
		float time = float(clock.restart().asMicroseconds());
		time = time / COEF_SPEED_GAME;
		if (isPause)
		{
			time = 0;
			isPause = false;
		}

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				board.dir = LEFT;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				board.dir = RIGHT;
			}
			else
			{
				board.dir = NONE;
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				ball.inBoard = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				isPause = true;
			}

		}
		if (window.isOpen())
		{
			if (isPause)
			{
				PauseMenu(window, font);
			}
			else
			{
				update(board, time, WINDOW_SIZE);
				if (ball.inBoard)
				{
					MoveBallInBoard(ball, board, time);
				}
				else
				{
					CollisionAndMove(ball, bricks, board, time, WINDOW_SIZE);
				};
				UpdateList(bricks);

				window.clear();
				window.draw(*(board.sprite));
				window.draw(*(ball.sprite));
				RenderList(bricks, window);
				window.display();

				if (bricks.size() == 0)
				{
					isWin = true;
				}
				if (ball.sprite->getPosition().y + ball.sprite->getRadius() >= WINDOW_SIZE.y)
				{
					isLose = true;
				}
			}
		}
	}
	DispolseGameObj(&board, &ball, bricks);
}

int main()
{
	RenderWindow window(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Arcanoid");
	bool isRetry = false;
	Font font;
	font.loadFromFile("font/font.otf");
	MainMenu(window, font, isRetry);
	while (isRetry)
	{
		isRetry = false;
		bool isWin = false;
		bool isLose = false;
		GameProcess(window, font, isWin, isLose);
		RetryMenu(window, font, isRetry, isWin, isLose);
	};
	return 0;
}