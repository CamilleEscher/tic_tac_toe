#include "Board.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>

Board::Board(std::size_t size)
{
	board = std::vector<char>(size, ' ');
}

void Board::display() const
{
	std::string		to_display;
	unsigned int	size = (int)std::round(std::sqrt(board.size()));
	bool			color = false;
	unsigned int	n = 1;
	unsigned int	space_nb;

	to_display += std::to_string(n);
	space_nb = Board::get_space(n);
	if(space_nb > 0)
	{
		to_display += add_spaces(space_nb);
	}
	print_line('-');
	for(unsigned int i = 0; i < size; ++i)
	{
		for(unsigned int j = 0; j < size; ++j)
		{
			to_display.push_back('|');
			if(board[i * size + j] == 'O')
			{
				to_display += "\033[0;31m";
				color = true;
			}
			else if(board[i * size + j] == 'X')
			{
				to_display += "\033[0;34m";
				color = true;
			}
			to_display.push_back(board[i * size + j]);
			if(color == true)
			{
				to_display += "\033[0m";
			}
			++n;
		}
		to_display.push_back('|');
		to_display += std::to_string(n - 1);
		std::cout << to_display << std::endl;
		print_line('-');
		if(n < board.size())
		{
			to_display = std::to_string(n);
			space_nb = Board::get_space(n);
			if(space_nb > 0)
			{
				to_display += add_spaces(space_nb);
			}
		}
	}
}

unsigned int Board::get_space(unsigned int n) const
{
	unsigned int	total_digit = 0;
	unsigned int	n_digit = 0;
	unsigned int	ten_power = 1;

	while(board.size() >= ten_power)
	{
		total_digit += 1;
		ten_power *= 10;
	}
	ten_power = 1;
	while(n >= ten_power)
	{
		n_digit += 1;
		ten_power *= 10;
	}
	return (total_digit - n_digit);
}

std::string Board::add_spaces(unsigned int space_nb) const
{
	std::string spaces;

	for(unsigned int i = 0; i < space_nb; ++i)
	{
		spaces += " ";
	}
	return spaces;
}

void Board::print_line(char c) const
{
	std::size_t	size = std::round(std::sqrt(board.size())) * 2 + 3;
	std::string	line(size, c);
	std::cout << line << std::endl;
}

bool Board::set_cell_value(unsigned int pos, char c)
{
	if(pos < board.size())
	{
		if(board[pos] == ' ') 
		{
			board[pos] = c;
			return true;
		}
	}
	return false;
}

bool Board::is_winner(char c) const
{
	bool has_won = false;

	if(check_line(c))
	{
		has_won = true;
	}
	else if(check_column(c))
	{
		has_won = true;
	}
	else if(check_diag(c))
	{
		has_won = true;
	}
	return has_won;
}

bool Board::check_line(char c) const
{
	unsigned int	count = 0;
	unsigned int	size = (int)std::round(std::sqrt(board.size()));

	for(unsigned int i = 0; i < size; ++i)
	{
		count = 0;
		for(unsigned int j = 0; j < size; ++j)
		{
			if(board[i * size + j] == c)
			{
				++count;
			}
			else
			{
				break;
			}
		}
		if(count == size)
		{
			return true;
		}
	}
	return false;
}

bool Board::check_column(char c) const
{
	unsigned int	size = (int)std::round(std::sqrt(board.size()));
	unsigned int	count = 0;

	for(unsigned int i = 0; i < size; ++i)
	{
		count = 0;
		for(unsigned int j = 0; j < size; ++j)
		{
			if(board[i + j * size] == c)
			{
				++count;
			}
			else
			{
				break;
			}
		}
		if(count == size)
		{
			return true;
		}
	}
	return false;
}

bool Board::check_diag(char c) const
{
	unsigned int	size = (int)std::round(std::sqrt(board.size()));
	unsigned int	count = 0;

	for(unsigned int i = 0; i < size; ++i)
	{
		if(board[i * (size + 1)] == c)
		{
			++count;
		}
		else
		{
			break;
		}
	}
	if(count == size)
	{
		return true;
	}
	count = 0;
	for(unsigned int i = size; i > 0; --i)
	{
		if(board[i * (size - 1)] == c)
		{
			++count;
		}
		else
		{
			break;
		}
	}
	if(count == size)
	{
		return true;
	}
	return false;	
}

unsigned int Board::get_size()
{
	return board.size();
}

bool Board::is_full() const
{
	auto res = std::find(std::begin(board), std::end(board), ' ');
	
	if(res == std::end(board))
	{
		return true;
	}
	return false;
}
