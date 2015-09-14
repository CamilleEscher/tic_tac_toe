#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>
#include <string>

class Board
{
	//TODO : size of array (Vector) initialized bythe user
	std::vector<char>	board;

public :
			Board(std::size_t size);
	
	void			display() const;
	bool			set_cell_value(unsigned int pos, char c);
	bool			is_winner(char c) const;
	bool			is_full() const;
	unsigned int	get_size();
private :
	void			print_line(char c) const;
	bool			check_line(char c) const;
	bool			check_column(char c) const;
	bool			check_diag(char c) const;
	unsigned int	get_space(unsigned int n) const;
	std::string		add_spaces(unsigned int space_nb) const;
};

#endif
