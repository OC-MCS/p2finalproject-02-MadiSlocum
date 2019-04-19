#include "CollidableSprite.h"

CollidableSprite::CollidableSprite(float x, float y, const BoundingHull * relative_hull)
	: absolute_hull(x+relative_hull->get_outer_rect().get_left(), x+relative_hull->get_outer_rect().get_right(),
		y+relative_hull->get_outer_rect().get_bottom(), y+relative_hull->get_outer_rect().get_top()), relative_hull(relative_hull)
{
	setPosition(x, y);
}

bool CollidableSprite::is_colliding(const CollidableSprite & CS) const
{
	return absolute_hull.is_overlapping(CS.absolute_hull);
}

void CollidableSprite::update( long long cur_time )
{
	absolute_hull = *relative_hull;
	absolute_hull.offset(getPosition().x, getPosition().y);
}