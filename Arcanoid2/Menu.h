#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

Text CreateText(String strText, Vector2f pos, Font & font, int size, bool isBold);
void MainMenu(RenderWindow &window, Font & font, bool &isRetry);
void PauseMenu(RenderWindow &window, Font & font);
void RetryMenu(RenderWindow & window, Font & font, bool &isRetry, bool isWin, bool isLose);
