#include "ProjectileShooter.h"
using namespace sf;
using namespace std;

ProjectileShooter::ProjectileShooter()
	:projectile_prototype(nullptr), projectiles_list(nullptr), time_stamp_last_fire(0)
{

}

void ProjectileShooter::fire_projectile(long long cur_time )
{
	if (cur_time - time_stamp_last_fire >= time_between_fires)
	{
		// Create a new projectile as a copy of the prototype, but set the position and velocity relative
		// to the shooter.
		ProjectileSprite new_projectile(*projectile_prototype);
		new_projectile.setPosition(getPosition() + spawn_offset);
		new_projectile.velocity = aim_vec;
		projectiles_list->push_back(new_projectile);
		time_stamp_last_fire = cur_time;
	}
}