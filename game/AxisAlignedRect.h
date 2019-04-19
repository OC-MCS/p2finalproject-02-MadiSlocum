#ifndef AXIS_ALIGNED_RECT_H
#define AXIS_ALIGNED_RECT_H

#include <cassert>

class AxisAlignedRect
{
private:

	// These shall satisfy ( left <= right ) and ( top <= bottom ), in accordance with orientation
	// of axes, i.e., x-axis points to the right, y-axis points down.
	float left;
	float right;
	float top;
	float bottom;

public:

	// Constructors
	AxisAlignedRect() {}	// todo
	AxisAlignedRect(float left, float right, float top, float bottom)
		: left(left), right(right), top(top), bottom(bottom) { assert(left <= right && top <= bottom); }

	// Assignment operators
	AxisAlignedRect & operator = (const AxisAlignedRect & R)
		{ left = R.left; right = R.right; top = R.top; bottom = R.bottom; return *this; }

	// Setters
	AxisAlignedRect & set(float left, float right, float bottom, float top)
	{ assert(left <= right && top <= bottom); this->left = left; this->right = right; this->top = top; this->bottom = bottom; return *this;	}

	// Accessors
	float get_left() const { return left; }
	float get_right() const { return right; }
	float get_top() const { return top; }
	float get_bottom() const { return bottom; }

	// Move current position x units to the right and y units down.
	void offset(float x, float y) { left += x; right += x; top += y; bottom += y; }

	// Overlap testing
	bool contains(const AxisAlignedRect & R) const { return left <= R.left && R.right <= right && top <= R.top && R.bottom <= bottom; }

	bool is_overlapping(const AxisAlignedRect & R) const { return !(right < R.left || R.right < left || R.bottom < top || bottom < R.top); }
};

#endif