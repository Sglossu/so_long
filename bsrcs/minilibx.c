#include <so_long_bonus.h>

// void	my_mlx_pixel_put(t_struct *slg, int x, int y, int color)
// {
// 	char *dst;

// 	dst = slg->img.addr + (y * slg->img.line_length + x * (slg->img.bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	key_hook(int keycode, t_data *vars)
{
	(void)vars;
	return (keycode);
}

int	close_window(void)
{
	printf("Exit\n");
	exit(0);
	return (1);
}

int	f_close(int keycode, t_struct *slg)
{
	if (keycode == ESC)
	{
		printf("Exit\n");
		exit(0);
	}
	slg->but = keycode;
	play(slg);
	return (0);
}

void	minilibx(t_struct *slg)
{
	slg->img.mlx_ptr = mlx_init();
	slg->img.mlx_win = mlx_new_window(slg->img.mlx_ptr, \
	slg->x_len * (slg->scale), slg->y_len * (slg->scale), "so_long");
	init_picture(slg);
	draw(slg);
	mlx_hook(slg->img.mlx_win, 2, 0, f_close, slg);
	mlx_hook(slg->img.mlx_win, 17, 0, close_window, NULL);
	mlx_loop_hook(slg->img.mlx_ptr, animation, slg);
	mlx_loop(slg->img.mlx_ptr);
}
