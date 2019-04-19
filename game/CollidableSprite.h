#ifndef COLLIDABLE_SPRITE_H
#define COLLIDABLE_SPRITE_H

#include <SFML/Graphics.hpp>
#include "BoundingHull.h"

class CollidableSprite : public virtual sf::Sprite
{
public:

	CollidableSprite() {} // todo
	CollidableSprite(float x, float y, const BoundingHull * relative_hull );
			// Top-left corner of outer_rect of relative_hull is assumed to be relative to the xy-position
			// of the Sprite. For instance, if xy-position is specified as (5,10), and left and top sides of
			// relative_hull are both 0, then the top-left corner of the absolute_hull will be set  to (5,10).
			// If xy-position is specified as (5,10), and left and top sides of relative_hull are both 1,
			// then the top-left corner of the absolute_hull will be set  to (6,11).

	bool is_colliding(const CollidableSprite & CS) const;

	void update( long long cur_time );

private:

	BoundingHull absolute_hull;
	const BoundingHull * relative_hull;
};

#endif