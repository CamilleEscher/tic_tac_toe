#ifndef GAME_HPP
#define GAME_HPP
#include "Board.hpp"

class Game
{
	Board*		board;
	int			round;
	char const	player1;
	char const	player2;
	int			current_player;
	bool		is_finished;
	int			winner_player;

public :
			Game();

	void	destroy();
	void	set_options();
	void	display();
	void	update();
	bool	is_winner();
	void	congrats();
	bool	exaequo();
	bool	check_finished();
	bool	get_is_finished();
};

#endif
