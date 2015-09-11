#include <iostream>
#include "Game.hpp"

int main()
{
	Game	game;

	game.display();
	while(!game.is_finished()) 
	{
		game.update();
		game.display();
	}
	return 0;
}
