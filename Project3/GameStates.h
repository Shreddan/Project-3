#pragma once
#include "Input.h"


struct GameStates
{
	enum gameState
	{
		MainMenu = 0,
		Intro = 1,
		GameScreen = 2,
		QuestScreen = 3,
		CharacterScreen = 4
	};

	GameStates();
	~GameStates();

	sf::View updateView(sf::View& view1, sf::Sprite sprite1);

	void GameLoop(Input& input, sf::Sprite& sprite1, sf::RenderWindow& window, TileMap& map, sf::Font font1, AnimationManager& animMan, sf::View& defview);

	void DrawState(sf::Sprite& sprite1, Input& input, sf::RenderWindow& window, TileMap map, sf::Font font1, sf::View view1, sf::View defview);



	int GameState;
	
	Input input;

	sf::View defview;
	
};

