#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include <string>
#include "SpaceInvadersWorld.h"

class SpaceInvadersGame
{
public:

	SpaceInvadersGame(const std::string & filename);	// todo

	void run();	// todo

private:

	sf::RenderWindow window;
	SpaceInvadersWorld world;
};

#endif
