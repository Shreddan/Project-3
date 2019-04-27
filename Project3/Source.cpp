#include "TileMap.h"
#include "AnimationManager.h"



	


AnimationManager animMan;
std::vector<sf::IntRect> frames;



void userInput(sf::Sprite& sprite1)
{
	float dirX = 0.f;
	float dirY = 0.f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dirY = -2.f;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dirY = 2.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		dirX = -2.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dirX = 2.f;
	}
	
	
	
	sprite1.move(dirX, dirY);

	
	
	int index = 0;

	if (dirY == -2.f)
	{
		index = 0 + (animMan.currentFrame / 10) % 3;
	}
	else if (dirY == 2.f)
	{
		index = 3 + (animMan.currentFrame / 10) % 3;
	}
	else if (dirX == -2.f)
	{
		index = 6 + (animMan.currentFrame / 10) % 2;
	}
	else if (dirX == 2.f)
	{
		index = 8 + (animMan.currentFrame / 10) % 2;
	}
	else
	{
		animMan.currentFrame = 3;
		index = 3;
	}

	
	sprite1.setTextureRect(frames[index]);
	
	animMan.currentFrame++;
}


int main()
{
	int width = 1400;
	int height = (width * 9) / 16;

	//Window
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML PlayGround");
	window.setFramerateLimit(60);


	// create the tilemap from the level definition
	
	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), map.level, map.mWidth, map.mHeight))
		return -1;


	//Sprites
	sf::Texture texture1;
	texture1.loadFromFile("CharSprites.png");
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
	sprite1.setPosition(100.f, 100.f);
	sprite1.setOrigin(10, 16);
	sprite1.setScale(2.f, 2.f);
	sprite1.setTextureRect(sf::IntRect(0, 0, 32, 32));

	//Font
	sf::Font font1;
	font1.loadFromFile("Ancient Modern Tales.otf");

	float rotation = 0.f;
	float rotatePlus = 4.f;

	float scaleX = 1.f;
	float scaleY = 1.f;

	float scaler = 0.5f;

	
	animMan.addFrames1(frames, sf::IntRect(32, 32, 32, 32), sf::IntRect(0, 64, 32, 32), sf::IntRect(32, 64, 32, 32), sf::IntRect(0, 0, 32, 32), sf::IntRect(32, 0, 32, 32), sf::IntRect(0, 32, 32, 32), sf::IntRect(0, 128, 32, 32), sf::IntRect(32, 128, 32, 32), sf::IntRect(0, 96, 32, 32), sf::IntRect(32, 96, 32, 32));

	while (window.isOpen())
	{
		sf::Event event;
		
		
		while (window.pollEvent(event))
		{
			
			userInput(sprite1);

			
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(map);
		window.draw(sprite1);
		window.display();
	}

	return 0;
}