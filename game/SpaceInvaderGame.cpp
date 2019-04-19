#include "SpaceInvadersGame.h"
#include "Stopwatch.h"
using namespace sf;
using namespace std;

SpaceInvadersGame::SpaceInvadersGame(const string & filename)
{
	// todo need to change this so that it gets the window height and width from a file rather than having them hard-coded here
	
	int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
	
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	world.set_window(&window);
}

void SpaceInvadersGame::run()
{
	world.load_start_splash("Filename we're not using yet.txt");
	
	// todo wait for the user to click in the "start button" sprite


	world.load_world("Filename we're not using yet.txt");

	Stopwatch tick_counter;
	tick_counter.start();
	long long last_update = 0;
	long long mills_per_tick = 33;	// Roughly 30 updates per second

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
		}

		if (tick_counter.getElapsedTime() - last_update >= mills_per_tick)
		{
			world.update(last_update = tick_counter.getElapsedTime());

			// draw background first, so everything that's drawn later 
			// will appear on top of background
			world.render();
		}

	} // end body of animation loop


}
