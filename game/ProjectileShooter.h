#ifndef PROJECTILE_SHOOTER_H
#define PROJECTILE_SHOOTER_H

#include <list>
#include "ProjectileSprite.h"

class ProjectileShooter : public virtual sf::Sprite
{
public:

	ProjectileShooter();

	void fire_projectile(long long cur_time);

	sf::Vector2f aim_vec;	// The projectile will be fired from the shooter in this direction.
							// More precisely, when a projectile is fired, the aim_vec is used
							// as the projectile's velocity
	sf::Vector2f spawn_offset;

	long long time_between_fires;	// The amount of time that must elapsed following the firing of a projectile
									// until another projectile may be fired.

	const ProjectileSprite * projectile_prototype;	// Pointer to a prototype for the projectile that will be fired by this
													// ProjectileShooter. A copy of this prototype is added to the projectiles
													// list with each call to fire_projectile().
	std::list<ProjectileSprite> * projectiles_list;

private:

	long long time_stamp_last_fire;	// The last time the shooter fired a projectile

};

#endif