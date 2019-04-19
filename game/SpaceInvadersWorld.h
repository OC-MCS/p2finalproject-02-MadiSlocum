#ifndef SPACE_INVADERS_WORLD_H
#define SPACE_INVADERS_WORLD_H

#include <list>
#include <string>
#include "PlayerSprite.h"
#include "AlienGroup.h"

class SpaceInvadersWorld
{
public:

	void set_window(sf::RenderWindow * pWindow);

	void load_start_splash(const std::string & filename);
	void load_world(const std::string & filename);

	void update(long long cur_millisec_count);
	void render() const;

private:

	// The following line is copied from sfml-dev.org:
	// "When you set the texture of a sprite, all it does internally is store a pointer to the texture instance."
	// So we need to store the texture instances somewhere that will persist for the duration of the game.
	sf::Texture start_background; //texture for the first background where the start button is 
	sf::Texture button_texture; 
	sf::Texture background_texture;
	sf::Texture ship_texture;
	sf::Texture alien_texture;	// Shared by all alien Sprites
	sf::Texture bomb_texture;	// Shared by all bomb Sprites
	sf::Texture missile_texture;// Shared by all missile Sprites

	ProjectileSprite bomb_prototype;	// The prototype of the projectile that the alien sprites will fire
	ProjectileSprite missile_prototype;	// The prototype of the projectile that the player sprite will fire
	AlienSprite alien_prototype;

	sf::Sprite start_sprite; 
	sf::Sprite background_sprite;
	PlayerSprite ship;
	AlienGroup aliens;
	std::list<ProjectileSprite> bombs;
	std::list<ProjectileSprite> missiles;

	sf::RenderWindow * pWindow;	// Pointer to the window that the world will be drawn to

	void clear_world();
};

#endif