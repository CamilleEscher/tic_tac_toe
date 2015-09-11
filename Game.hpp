#ifndef GAME_HPP
#define GAME_HPP
#include "Board.hpp"

class Game
{
	Board	board;
	int		round;
	char	player1;
	char	player2;

	public :
		Game();

		void	display(int player);
		Game&	update(int player);
		bool	is_winner(int player);
		void	congrats(int player);
		bool	exaequo(int player);
};

#endif
