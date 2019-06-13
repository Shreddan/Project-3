#include "GameStates.h"






int main()
{
	GameStates gamestate;

	int width = 1500;
	int height = (width * 9) / 16;

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML PlayGround");
	window.setFramerateLimit(60);

	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), map.level, map.mWidth, map.mHeight, map.tileNumber))
	{
		return -1;
	} 




	sf::Texture texture1;
	texture1.loadFromFile("CharSprites.png");

	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
	sprite1.setPosition(gamestate.input.player1X, gamestate.input.player1Y);
	sprite1.setOrigin(16, 16);
	sprite1.setScale(2.f, 2.f);
	sprite1.setTextureRect(sf::IntRect(0, 0, 32, 32));   

	sf::Font font1;
	font1.loadFromFile("Ancient Modern Tales.otf");

	gamestate.GameLoop(gamestate.input, sprite1, window, map, font1, gamestate.input.animMan, gamestate.defview);
	return 0;
}