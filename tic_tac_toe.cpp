#include <iostream>
#include "Game.hpp"
#include <csignal>

static Game game;

void interrupt(int signum)
{
	std::cout << std::endl << "Interrupted by " << signum << std::endl;
	game.destroy();
	exit(0);
}

int main()
{
	signal(SIGINT, interrupt);
	game.set_options();
	game.display();
	while(!game.get_is_finished()) 
	{
		game.update();
		game.display();
	}
	game.destroy();
	return 0;
}
