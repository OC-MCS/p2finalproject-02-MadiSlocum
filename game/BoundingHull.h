#ifndef BOUNDING_HULL_H
#define BOUNDING_HULL_H

#include <vector>
#include "AxisAlignedRect.h"

class BoundingHull
{
public:

	BoundingHull() {} // todo
	BoundingHull(float left, float right, float top, float bottom);	// Sets outer_rect to specified parameters. Leaves interior empty

	BoundingHull & operator = (const BoundingHull &);

	void push_interior_hull(const BoundingHull &);	// Interior hulls shall lie entirely inside the boundaries of outer_rect

	const AxisAlignedRect & get_outer_rect() const;
	
	bool is_overlapping(const BoundingHull &) const;

	// Move position of outer_rect and all interior_hulls x units to the right and y units down.
	void offset(float x, float y);

private:

	AxisAlignedRect outer_rect;	// The outer "shell" of the hull. If the outer rects of two BoundingHulls are not
								// overlapping, there's no need to consider the inner hulls.
	std::vector<BoundingHull> interior_hulls;	// A more refined definition of the shape of the hull. Can be empty.
};

#endif