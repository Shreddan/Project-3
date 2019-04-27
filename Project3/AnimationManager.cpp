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

//void frameLoop(int currentFrame, int nrofFrames, )
