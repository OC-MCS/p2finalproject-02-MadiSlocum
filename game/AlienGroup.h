#pragma once

#include <list>
#include "AlienSprite.h"

class AlienGroup : public sf::Sprite
{
public:

	void set_prototype(AlienSprite * alien_prototype);
	void spawn_group(float top_left_x, float top_left_y, size_t initial_count);

	void update( long long cur_time );

	const std::list<AlienSprite> * get_aliens_list() const;
	std::list<AlienSprite> * get_aliens_list();

private:

	AlienSprite * alien_prototype;

	std::list<AlienSprite> aliens;

};
