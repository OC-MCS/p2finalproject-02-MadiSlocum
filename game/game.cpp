#include <iostream>
#include "SpaceInvadersGame.h"
using namespace std;
using namespace sf;

int main()
{
	SpaceInvadersGame mygame("game_parameters.txt");
	mygame.run();

	return 0;
}