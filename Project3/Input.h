#pragma once
#include "TileMap.h"
#include "AnimationManager.h"

struct Input
{
	Input();
	~Input();

	void Inputs(sf::Sprite& sprite1, sf::RenderWindow& window, float& dirX, float& dirY, int height, int width);

	void MenuInput(bool& startSelected, bool& loadSelected, bool& optionsSelected);

	

	bool mouseClick;

	bool startSelected;
	bool loadSelected;
	bool optionsSelected;

	int player1X;
	int player1Y;

	float dirX;
	float dirY;

	AnimationManager animMan;
	


};

