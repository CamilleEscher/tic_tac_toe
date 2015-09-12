#include "Game.hpp"
#include "Board.hpp"
#include <iostream>
#include <limits>

Game::Game() :
	board(nullptr),
	round(1),
	player1('O'),
	player2('X'),
	//player1_name("Player 1");TODO
	//player2_name("Player 2"); TODO
	current_player(0),
	is_finished(false),
	winner_player(0)
{
}

void Game::destroy()
{
	delete board;
	board = NULL;
}

void Game::set_options()
{
	unsigned int side;

	do
	{
		std::cout << "Enter the size of the side of the board (3 - 300)" << std::endl;
		std::cin >> side;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while(side < 3 || side > 300);
	board = new Board(side * side);
}

namespace
{
	static void round_display(int round)
	{
		std::cout << " Round " << round << std::endl;
	}

	static void ask_next_move(int current_player, char c_player, std::size_t board_size)
	{
		std::cout << "Player " << (current_player + 1) << " (" << c_player << ")" << ", please enter your move (1 - " << board_size << ") ?" << std::endl;
	}
}

void Game::display()
{
	round_display(round);
	board->display();
	if(winner_player > 0)
	{
		Game::congrats();
	}
	else if(winner_player == 0 && is_finished)
	{
		std::cout << "Ex-aequo ! " << std::endl;
	}
}

void Game::update()
{
	unsigned int	pos = 0;
	char			c;
	bool			is_in_board = false;
	
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
		ask_next_move(current_player, c, board->get_size());
		std::cin >> pos;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		is_in_board = board->set_cell_value((pos - 1), c);
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
	if(board->is_winner(c))
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
	return board->is_full();
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
