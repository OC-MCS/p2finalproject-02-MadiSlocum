#include "AutoMovingSprite.h"
using namespace sf;

//AutoMovingSprite::AutoMovingSprite(unsigned int move_freq, Vector2f velocity)
//	:move_freq(move_freq), velocity(velocity), time_stamp_last_move(0)
//{
//
//}

AutoMovingSprite::AutoMovingSprite(const Vector2f & velocity)
	: velocity(velocity)
{

}

//void AutoMovingSprite::update(long long cur_time)
void AutoMovingSprite::update( long long cur_time )
{
	//if (cur_time - time_stamp_last_move >= move_freq)
	//{
	//	setPosition(getPosition() + velocity);	// offset sprite's position by its velocity
	//	time_stamp_last_move = cur_time;
	//}

	setPosition(getPosition() + velocity);
}