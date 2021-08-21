#include "../includes/so_long.h"

t_struct	init_struct(t_struct slg)
{
	slg.x_len = 0;
	slg.y_len = 0;
	slg.emp = '0';
	slg.wall = '1';
	slg.thg = 'C';
	slg.exit = 'E';
	slg.plr = 'P';
	slg.valid = 1;
	return (slg);
}