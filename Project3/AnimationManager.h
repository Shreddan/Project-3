#pragma once
#include "includes.h"

struct AnimationManager
{

	AnimationManager();
	~AnimationManager();

	
	
	int currentFrame = 0;
	int nrOfFrames = 0;



	std::vector<sf::IntRect> frames;
	std::vector<sf::IntRect> frames1;
	

	void addFrames1(std::vector<sf::IntRect> &frames, sf::IntRect frame1, sf::IntRect frame2, sf::IntRect frame3, sf::IntRect frame4, sf::IntRect frame5, sf::IntRect frame6, sf::IntRect frame7, sf::IntRect frame8, sf::IntRect frame9, sf::IntRect frame10);

	void frameloop(sf::Sprite& sprite1, float dirX, float dirY, std::vector<sf::IntRect>& frames, std::vector<sf::IntRect>& frames1);
	

	
	
};

