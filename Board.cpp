#include "Board.hpp"
#include <iostream>
#include <string>

static void print_line(int char_nb, char c);

Board::Board()
{
	int i = -1;

	while(++i < 9)
	{
		this->board[i] = ' ';
	}	
}

void Board::display()
{
	int 		i = -1;
	int 		j = -1;
	std::string to_display = " ";

	print_line(9, '-');
	while(++i < 3)
	{
		while(++j < 3)
		{
			to_display += "|";
			to_display.push_back(board[i * 3 + j]);
		}
		to_display += "|";
		std::cout << to_display << std::endl;
		print_line(9, '-');
		j = -1;
		to_display = " ";
	}
}

static void print_line(int char_nb, char c)
{
	int			i = -1;
	std::string	line = "";

	while(++i < char_nb)
	{
		line += c;
	}
	std::cout << line << std::endl;
}

Board& Board::update(int pos, char c)
{
	if(pos > -1 && pos < 9)
	{
		if(board[pos] == ' ')
		{
			board[pos] = c;
		}
	}
	return *this;
}

static bool check_line(char c, char const* board);

static bool check_column(char c, char const* board);

static bool check_diag(char c, char const* board);

bool Board::is_winner(char c)
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
	int		i = -1;
	int		j = -1;
	int		count = 0;
	bool	has_won = false;

	while(++i < 3)
	{
		count = 0;
		while(++j < 3)
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
		j = -1;
		if(count == 3)
		{
			has_won = true;
			break;
		}
	}
	return has_won;
}

static bool check_column(char c, char const* board)
{
	int		i = -1;
	bool	has_won = false;

	while(++i < 3)
	{
		if(board[i] == c)
		{
			if(board[i + 3] == c && board[i + 6] == c)
			{
				has_won = true;
				break;
			}
		}
	}
	return has_won;
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

bool Board::is_full()
{
	int		i = -1;
	bool	isfull = false;

	while(++i < 9)
	{
		if(board[i] == ' ')
		{
			break;
		}
	}
	if(i == 9)
	{
		isfull = true;
	}
	return isfull;
}

bool Board::is_space(int pos)
{
	bool isspace = true;
	if(pos > 0 && pos < 10)
	{
		if(board[pos - 1] != ' ')
		{
			isspace = false;
		}
	}
	else
	{
		isspace = false;
	}
	return isspace;
}
