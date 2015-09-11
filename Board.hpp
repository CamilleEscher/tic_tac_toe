#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	char	board[9];
	int		board_size;
public :
			Board();
	
	void	display() const;
	bool	set_cell_value(int pos, char c);
	bool	is_winner(char c) const;
	bool	is_full() const;
};

#endif
