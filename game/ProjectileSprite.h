#ifndef PROJECTILE_SPRITE_H
#define PROJECTILE_SPRITE_H

#include "CollidableSprite.h"
#include "AutoMovingSprite.h"

class ProjectileSprite : public AutoMovingSprite, public CollidableSprite
{
public:

	ProjectileSprite() {}

	void update( long long cur_time );
};

#endif