#include <so_long.h>

t_struct	init_struct(t_struct slg)
{
	slg.x_len = 0;
	slg.y_len = 0;
	slg.emp = '\0';
	slg.wall = '\0';
	slg.thg = '\0';
	slg.exit = '\0';
	slg.plr = '\0';
	slg.valid = 1;
	slg.flag = 1;
	slg.scale = 10;
	slg.p_x = 0;
	slg.p_y = 0;
	slg.cltb = 0;
	slg.scale = 20;
	slg.step = 0;
	return (slg);
}