#include "Board.hpp"
#include <iostream>
#include <string>

static void print_line(int char_nb, char c);

Board::Board() :
	board_size(9)
{
	for(unsigned int i = 0; i < board_size; ++i)
	{
		board[i] = ' ';
	}	
}

void Board::display() const
{
	std::string to_display;

	to_display.push_back(' ');
	print_line(board_size, '-');
	for(unsigned int i = 0; i < 3; ++i)
	{
		for(unsigned int j = 0; j < 3; ++j)
		{
			to_display.push_back('|');
			to_display.push_back(board[i * 3 + j]);
		}
		to_display.push_back('|');
		std::cout << to_display << std::endl;
		print_line(board_size, '-');
		to_display = " ";
	}
}

//fonction membre TODO
static void print_line(int char_nb, char c)
{
	std::string	line;

	for(unsigned int i = 0; i < char_nb; ++i)
	{
		line += c;
	}
	std::cout << line << std::endl;
}

bool Board::set_cell_value(int pos, char c)
{
	if(pos > -1 && pos < board_size)
	{
		if(board[pos] == ' ')
		{
			board[pos] = c;
			return true;
		}
	}
	return false;
}

static bool check_line(char c, char const* board);

static bool check_column(char c, char const* board);

static bool check_diag(char c, char const* board);

bool Board::is_winner(char c) const
{
	bool has_won = false;

	if(check_line(c, board))
	{
		has_won = true;
	}
	else if(check_column(c, board))
	{
		has_won = true;
	}
	else if(check_diag(c, board))
	{
		has_won = true;
	}
	return has_won;
}

static bool check_line(char c, char const* board)
{
	int		count = 0;

	for(unsigned int i = 0; i < 3; ++i)
	{
		count = 0;
		for(unsigned int j = 0; j < 3; ++j)
		{
			if(board[i * 3 + j] == c)
			{
				++count;
			}
			else
			{
				break;
			}
		}
		if(count == 3)
		{
			return true;
		}
	}
	return false;
}

static bool check_column(char c, char const* board)
{
	for(unsigned int i = 0; i < 3; ++i)
	{
		if(board[i] == c)
		{
			if(board[i + 3] == c && board[i + 6] == c)
			{
				return true;
			}
		}
	}
	return false;
}

static bool check_diag(char c, char const* board)
{
	bool has_won = false;

	if(board[0] == c && board[4] == c && board[8] == c)
	{
		has_won = true;
	}
	else if(board[2] == c && board[4] == c && board[6] == c)
	{
		has_won = true;
	}
	return has_won;
}

bool Board::is_full() const
{
	for(unsigned int i = 0; i < board_size; ++i)
	{
		if(board[i] == ' ')
		{
			return false;
		}
	}
	return true;
}
