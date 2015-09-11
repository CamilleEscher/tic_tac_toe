#include "Game.hpp"
#include "Board.hpp"
#include <iostream>
#include <limits>

Game::Game() :
	round(1),
	player1('O'),
	player2('X'),
	current_player(0),
	is_finished(false),
	winner_player(0)
{
}

namespace
{
	static void round_display(int round)
	{
		std::cout << " Round " << round << std::endl;
	}

	static void ask_next_move(int current_player)
	{
		std::cout << "Player " << (current_player + 1) << ", please enter your move (1-9) ?" << std::endl;
	}
}

void Game::display()
{
	round_display(round);
	board.display();
	if(winner_player > 0)
	{
		Game::congrats();
	}	
}

void Game::update()
{
	int			pos = 0;
	char		c;
	bool		is_in_board = false;
	
	if(current_player == 0)
	{
		c = player1;
	}
	else
	{
		c = player2;
	}
	while(!is_in_board)
	{
		ask_next_move(current_player);
		std::cin >> pos;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		is_in_board = board.set_cell_value((pos - 1), c);
	}
	++round;
	is_finished = check_finished();
	current_player = (current_player + 1) % 2;
}

bool Game::is_winner()
{
	bool 		has_won = false;
	char 		c;
	
	if(current_player == 0)
	{
		c = player1;
	}
	else
	{
		c = player2;
	}
	if(board.is_winner(c))
	{
		has_won = true;
		winner_player = current_player + 1;
	}
	return has_won;
}

void Game::congrats()
{
	std::cout << "Player " << winner_player << " win !" << std::endl;
}

bool Game::exaequo()
{
	bool res;

	res = board.is_full();
	if(res && !(is_winner()))
	{
		std::cout << "Ex-aequo ! " << std::endl;
	}
	return res;
}

bool Game::check_finished()
{
	bool finished = false;
	if(is_winner() || exaequo())
	{
		finished = true;
	}
	return finished;
}

bool Game::get_is_finished()
{
	return is_finished;
}
