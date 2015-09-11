#include <iostream>
#include "Game.hpp"

int main()
{
	Game	game;
	int		player = 0;

	game.display(player);
	while(!game.is_winner((player + 1) % 2) && !game.exaequo((player + 1) % 2))
	{
		game.update(player);
		game.display(player);
		player = ++player % 2;
	}
	return 0;
}
