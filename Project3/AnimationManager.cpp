#include "AnimationManager.h"



AnimationManager::AnimationManager()
{
}


AnimationManager::~AnimationManager()
{
}




void AnimationManager::addFrames1(std::vector<sf::IntRect>& frames, sf::IntRect frame1, sf::IntRect frame2, sf::IntRect frame3, sf::IntRect frame4, sf::IntRect frame5, sf::IntRect frame6, sf::IntRect frame7, sf::IntRect frame8, sf::IntRect frame9, sf::IntRect frame10)
{
	frames.emplace_back(frame1);
	frames.emplace_back(frame2);
	frames.emplace_back(frame3);
	frames.emplace_back(frame4);
	frames.emplace_back(frame5);
	frames.emplace_back(frame6);
	frames.emplace_back(frame7);
	frames.emplace_back(frame8);
	frames.emplace_back(frame9);
	frames.emplace_back(frame10);

}

void AnimationManager::frameloop(sf::Sprite& sprite1, float dirX, float dirY , std::vector<sf::IntRect>& frames, std::vector<sf::IntRect>& frames1)
{
	int index = 0;

	if (dirY == -3.f)
	{
		index = 0 + (currentFrame / 10) % 3;
	}
	else if (dirY == 3.f)
	{
		index = 3 + (currentFrame / 10) % 3;
	}
	else if (dirX == -3.f)
	{
		index = 6 + (currentFrame / 10) % 2;
	}
	else if (dirX == 3.f)
	{
		index = 8 + (currentFrame / 10) % 2;
	}
	else
	{
		index = 3;
	}



	sprite1.setTextureRect(frames[index]);

	currentFrame++;
}

