#include <iostream>
#include "SpaceInvadersWorld.h"
using namespace sf;
using namespace std;

void SpaceInvadersWorld::set_window(sf::RenderWindow * pWindow)
{
	this->pWindow = pWindow;
}

void SpaceInvadersWorld::load_start_splash(const std::string & filename)
{
	// todo use the input file parameters to load the world (right now it's all just hard-coded below)

	// Set the background texture and scale the sprite so that it covers the full window
	start_sprite.setTexture(start_background);
	start_sprite.setScale((float)pWindow->getSize().x / start_background.getSize().x,
							(float)pWindow->getSize().y / start_background.getSize().y);
}

void SpaceInvadersWorld::load_world(const string & filename)
{
	void clear_world();

	// todo use the input file parameters to load the world (right now it's all just hard-coded below)

	if ( !background_texture.loadFromFile("stars.jpg") )
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	if (!ship_texture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	if (!missile_texture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	
	///loading alien bomb & button texture
	if (!alien_texture.loadFromFile("alienText.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}
	if (!bomb_texture.loadFromFile("bombpic.png"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	if( !start_background.loadFromFile("startbackground.png"))
	{
		cout << "Unable to load start background texture!" << endl;
		exit(EXIT_FAILURE);
	}
	if (!button_texture.loadFromFile("startbutton.png"))
	{
		cout << "Unable to load button texture!" << endl;
		exit(EXIT_FAILURE);
	}
	//todo add in the button texture with the background to display these first thing when the game starts.
	//set a position of the start button so we know how to activate the game based on where the user clicks
	
	// Set the background texture and scale the sprite so that it covers the full window
	background_sprite.setTexture(background_texture);
	background_sprite.setScale((float)pWindow->getSize().x/background_texture.getSize().x,
								(float)pWindow->getSize().y / background_texture.getSize().y);

	// Set the initial parameters of the ship: Texture, position (centered horizontally and about 3/4 of the way down the window),
	// the aim direction and offset used when firing projectiles, etc.
	ship.setTexture(ship_texture);
	ship.setPosition(0.5f * (pWindow->getSize().x - ship.getTextureRect().width ), 0.75f  * pWindow->getSize().y);
	ship.projectile_prototype = &missile_prototype;
	ship.projectiles_list = &missiles;
	ship.aim_vec.x = 0.0f;
	ship.aim_vec.y = -5.0f;
	ship.spawn_offset.x = 0.0f;
	ship.spawn_offset.y = -5.0f;
	ship.time_between_fires = 250;	// Make the player wait about 1/4 second between successive fires

	alien_prototype.setTexture(alien_texture);
	alien_prototype.setScale(0.25f, 0.25f);
	alien_prototype.projectile_prototype = &bomb_prototype;
	alien_prototype.projectiles_list = &bombs;
	alien_prototype.aim_vec.x = 0.0f;
	alien_prototype.aim_vec.y = 5.0f;
	alien_prototype.spawn_offset.x = 0.0f;
	alien_prototype.spawn_offset.y = 5.0f;
	alien_prototype.time_between_fires = 0;

	aliens.set_prototype(&alien_prototype);
	//aliens.spawn_group(0.5f * (pWindow->getSize().x - alien_prototype.getTextureRect().width * 10), 0.25f  * pWindow->getSize().y, 10);
	aliens.spawn_group(0.05f * pWindow->getSize().x , 0.25f  * pWindow->getSize().y, 10);

	// Set the initial parameters of the missile prototype
	missile_prototype.setTexture(missile_texture);
	
	// todo initialize the remaining sprites in the world (aliens, bomb prototype)

}

void SpaceInvadersWorld::update(long long cur_millisec_count)
{
	// Update all of the positions of the sprites one at a time
	ship.update(cur_millisec_count);
	aliens.update(cur_millisec_count);
	for (list<ProjectileSprite>::iterator it = missiles.begin(); it != missiles.end(); ++it)
		it->update(cur_millisec_count);
	for (list<ProjectileSprite>::iterator it = bombs.begin(); it != bombs.end(); ++it)
		it->update(cur_millisec_count);

	// Check for collisions between aliens and missiles
	for (list<AlienSprite>::iterator alien_it = aliens.get_aliens_list()->begin(); alien_it != aliens.get_aliens_list()->end(); )
	{
		bool alien_killed = false;
		for (list<ProjectileSprite>::iterator missile_it = missiles.begin(); missile_it != missiles.end(); )
		{
			if (alien_it->getGlobalBounds().intersects(missile_it->getGlobalBounds()))
			{
				alien_it = aliens.get_aliens_list()->erase(alien_it);
				missile_it = missiles.erase(missile_it);
				alien_killed = true;
				break;
			}
			else
				++missile_it;
		}
		if (!alien_killed)
			++alien_it;
	}
}

void SpaceInvadersWorld::render() const
{
	// Draw all of the sprites to the window
	pWindow->draw(background_sprite);
	pWindow->draw(ship);
	for (list<ProjectileSprite>::const_iterator it = missiles.begin(); it != missiles.end(); ++it)
		pWindow->draw(*it);
	for (list<ProjectileSprite>::const_iterator it = bombs.begin(); it != bombs.end(); ++it)
		pWindow->draw(*it);
	for (list<AlienSprite>::const_iterator it = aliens.get_aliens_list()->begin(), IT = aliens.get_aliens_list()->end(); it != IT; ++it)
		pWindow->draw(*it);

	// Show the pWindow-> This makes everything that we have drawn to the pWindow actually show up on the screen
	pWindow->display();
}

void SpaceInvadersWorld::clear_world()
{
	bombs.clear();
	missiles.clear();
}