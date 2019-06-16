#include "Input.h"

Input::Input()
{
	//this->mouseClick = false;

	this->startSelected = true;
	this->loadSelected = false;
	this->optionsSelected = false;


	this->player1X = 300.f;
	this->player1Y = 300.f;

	this->dirX = 0.f;
	this->dirY = 0.f;

}

Input::~Input()
{
}

void Input::Inputs(sf::Sprite& sprite1, sf::RenderWindow& window, float& dirX, float& dirY, int height, int width)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite1.getPosition().y > 0)
	{
		std::cout << "W key Pressed!" << std::endl;
		dirY = -3.f;
		if (dirY < -3.f)
		{
			dirY = -3.f;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite1.getPosition().y < height + 85)
	{
		std::cout << "S key Pressed!" << std::endl;
		dirY = 3.f;
		if (dirY > 3.f)
		{
			dirY = 3.f;
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite1.getPosition().x > 45)
	{
		std::cout << "A key Pressed!" << std::endl;
		dirX = -3.f;
		if (dirX < -3.f)
		{
			dirX = -3.f;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite1.getPosition().x < width - 100)
	{
		std::cout << "D key Pressed!" << std::endl;
		dirX = 3.f;
		if (dirX > 3.f)
		{
			dirX = 3.f;
		}
	}


	sprite1.move(dirX, dirY);

	animMan.frameloop(sprite1, dirX, dirY, animMan.frames, animMan.frames1);
	

	dirX = 0;
	dirY = 0;

}

void Input::MenuInput(bool& startSelected, bool& loadSelected, bool& optionsSelected)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && startSelected)
	{
		startSelected = false;
		loadSelected = true;
		std::cout << std::boolalpha;
		std::cout << "start " << startSelected << std::endl;
		std::cout << "load " << loadSelected << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && loadSelected == true)
	{
		startSelected = false;
		loadSelected = false;
		optionsSelected = true;
		std::cout << "load " << loadSelected << std::endl;
		std::cout << "options " << optionsSelected << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && optionsSelected == true)
	{
		optionsSelected = false;
		loadSelected = true;
		std::cout << "options " << optionsSelected << std::endl;
		std::cout << "load " << loadSelected << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && loadSelected)
	{
		loadSelected = false;
		startSelected = true;
		std::cout << "load " << loadSelected << std::endl;
		std::cout << "start " << startSelected << std::endl;
	}
}



