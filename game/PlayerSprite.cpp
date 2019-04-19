#include "PlayerSprite.h"
using namespace sf;

void PlayerSprite::update( long long cur_time )
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		move(-DISTANCE, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		move(DISTANCE, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		fire_projectile(cur_time);
	}
}