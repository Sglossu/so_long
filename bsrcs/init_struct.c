#include <so_long_bonus.h>

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
	slg.scale = 50;
	slg.step = 0;
	slg.ani = 0;
	slg.count_img = 0;
	slg.img.player_cur = "texture/ping_right_close.xpm";
	slg.img.player_r = "texture/ping_right_open.xpm";
	slg.img.player_l = "texture/ping_right_close.xpm";
	return (slg);
}

void	init_player_struct_d(t_struct *slg)
{
	slg->img.player_cur = "texture/ping_right_close.xpm";
	slg->img.player_r = "texture/ping_right_open.xpm";
	slg->img.player_l = "texture/ping_right_close.xpm";
}

void	init_player_struct_a(t_struct *slg)
{
	slg->img.player_cur = "texture/ping_left_close.xpm";
	slg->img.player_r = "texture/ping_left_open.xpm";
	slg->img.player_l = "texture/ping_left_close.xpm";
}