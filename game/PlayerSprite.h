#ifndef PLAYER_SPRITE_H
#define PLAYER_SPRITE_H

#include "ProjectileShooter.h"

class PlayerSprite : public CollidableSprite, public ProjectileShooter
{
public:

	void update( long long cur_time );

};

#endif
