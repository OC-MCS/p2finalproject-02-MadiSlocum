#include "AlienGroup.h"
#include "Stopwatch.h"
using namespace sf;
using namespace std;

void AlienGroup::set_prototype(AlienSprite * alien_prototype)
{
	this->alien_prototype = alien_prototype;
}

void AlienGroup::spawn_group(float top_left_x, float top_left_y, size_t initial_count)
{
	for (size_t i = 0; i < initial_count; ++i)
	{
		aliens.push_back(*alien_prototype);
		aliens.back().setPosition(top_left_x, top_left_y);
		top_left_x += alien_prototype->getGlobalBounds().width;	// todo maybe use my collision rectangle instead of sfml's rectangle?
	}
}

void AlienGroup::update( long long cur_time )
{
	// todo
}

const list<AlienSprite> * AlienGroup::get_aliens_list() const
{
	return &aliens;
}

list<AlienSprite> * AlienGroup::get_aliens_list()
{
	return &aliens;
}