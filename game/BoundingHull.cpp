#include "BoundingHull.h"

BoundingHull::BoundingHull(float left, float right, float top, float bottom)
	: outer_rect(left, right, top, bottom)
{

}

BoundingHull & BoundingHull::operator = (const BoundingHull & BH)
{
	outer_rect = BH.outer_rect;
	interior_hulls = BH.interior_hulls;
	return *this;
}

void BoundingHull::push_interior_hull(const BoundingHull & BH)
{
	assert(outer_rect.contains(BH.outer_rect));
	interior_hulls.push_back(BH);
}

bool BoundingHull::is_overlapping(const BoundingHull & BH) const
{
	if (!outer_rect.is_overlapping(BH.outer_rect))
		return false;

	for (std::vector<BoundingHull>::const_iterator it = interior_hulls.begin(); it != interior_hulls.end(); ++it)
	{
		if (BH.is_overlapping(*it))
			return true;
	}

	return false;
}

const AxisAlignedRect & BoundingHull::get_outer_rect() const
{
	return outer_rect;
}

void BoundingHull::offset(float x, float y)
{
	outer_rect.offset(x, y);
	for (std::vector<BoundingHull>::iterator it = interior_hulls.begin(); it != interior_hulls.end(); ++it)
		it->offset(x, y);
}