#ifndef AUTO_MOVING_SPRITE_H
#define AUTO_MOVING_SPRITE_H

#include <SFML/Graphics.hpp>

class AutoMovingSprite : public virtual sf::Sprite
{
public:

	AutoMovingSprite() {}
	//AutoMovingSprite(unsigned int move_freq, sf::Vector2f velocity);
	AutoMovingSprite(const sf::Vector2f & velocity);

	//void update(long long cur_time);
	void update( long long cur_time );

	//long long move_freq;	// The amount of time that elapses between each movement
	sf::Vector2f velocity;	// Update function offsets sprite's position by this vector each movement.
							// The speed of the sprite is roughly |velocity| / move_freq.

private:

	//long long time_stamp_last_move;	// The time stamp of the last change in the sprite's position

	// Remark: cur_time, move_freq, and time_stamp_last_move shall be measured in the same units
};

#endif