#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	char	board[9];

	public :
				Board();
		void	display();
		Board&	update(int pos, char c);
		bool	is_winner(char c);
		bool	is_full();
		bool	is_space(int pos);
};

#endif
