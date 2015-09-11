#include "Game.hpp"
#include "Board.hpp"
#include <iostream>
#include <limits>

Game::Game() :
	round(1),
	player1('O'),
	player2('X')
{
}

namespace
{
	static void round_display(int round);
}

void Game::display(int player)
{
	round_display(round);
	board.display();
}

static void round_display(int round)
{
	std::cout << " Round " << round << std::endl;
}

static void ask_next_move(int player)
{
	std::cout << "Player " << (player + 1) << ", please enter your move (1-9) ?" << std::endl;
}

Game& Game::update(int player)
{
	int			pos = 0;
	char		c;

	if(player == 0)
	{
		c = player1;
	}
	else
	{
		c = player2;
	}
	++round;
	do
	{
		ask_next_move(player);
		std::cin >> pos;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while(!board.is_space(pos));
	board.update((pos - 1), c);
	return *this;
}

bool Game::is_winner(int player)
{
	bool 		has_won = false;
	char 		c;
	
	if(player == 0)
	{
		c = player1;
	}
	else
	{
		c = player2;
	}
	if(board.is_winner(c))
	{
		Game::congrats(player);
		has_won = true;
	}
	return has_won;
}

void Game::congrats(int player)
{
	std::cout << "Player " << player + 1 << " win !" << std::endl;
}

bool Game::exaequo(int player)
{
	bool res;

	res = board.is_full();
	if(res && !((*this).is_winner(player)))
	{
		std::cout << "Ex-aequo ! " << std::endl;
	}
	return res;
}
