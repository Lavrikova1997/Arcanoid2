#include "Menu.h"

Text CreateText(String strText, Vector2f pos, Font & font, int size, bool isBold = false)
{
	Text text(strText, font, size);
	text.setPosition(pos);
	if (isBold)
	{
		text.setStyle(Text::Bold | Text::Italic);
	}
	else
	{
		text.setStyle(Text::Italic);
	}
	text.setColor(Color::Cyan);

	return text;
}
void MainMenu(RenderWindow &window, Font & font, bool &isRetry)
{

	Text text = CreateText("Arcanoid", Vector2f(200.f, 250.f), font, 72, true);
	Text textStart = CreateText("Press Space for start", Vector2f(200.f, 350.f), font, 30);
	Text textExit = CreateText("Press Esc for Exit", Vector2f(200.f, 400.f), font, 30);
	Event event;
	while (window.isOpen() && (!isRetry))
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			};
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				isRetry = true;
			};
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		};
		if (window.isOpen())
		{
			window.clear();
			window.draw(text);
			window.draw(textStart);
			window.draw(textExit);
			window.display();
		};
	}
}
void PauseMenu(RenderWindow &window, Font & font)
{
	bool isPause = true;
	while (window.isOpen() && (isPause))
	{
		Text textStart = CreateText("Press O for continue", Vector2f(200.f, 350.f), font, 30);
		Text textExit = CreateText("Press Esc for Exit", Vector2f(200.f, 400.f), font, 30);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			};
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				isPause = false;
			};
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		};
		if (window.isOpen())
		{
			window.clear();
			window.draw(textStart);
			window.draw(textExit);
			window.display();
		}
	};
}
void RetryMenu(RenderWindow & window, Font & font, bool &isRetry, bool isWin, bool isLose)
{
	Text textWinLose = CreateText("", Vector2f(200.f, 250.f), font, 72, true);
	Text textRetry = CreateText("Press Space for Restart", Vector2f(200.f, 350.f), font, 30);
	Text textExit = CreateText("Press Esc for Exit", Vector2f(200.f, 400.f), font, 30);
	if (isWin)
	{
		textWinLose.setString("You win");
	}
	else if (isLose)
	{
		textWinLose.setString("You lose");
	}

	Event event;
	while (window.isOpen() && (!isRetry))
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			};
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				isRetry = true;
			};
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		};
		if (window.isOpen())
		{
			window.clear();
			window.draw(textWinLose);
			window.draw(textRetry);
			window.draw(textExit);
			window.display();
		};
	}
}
