#include <so_long.h>

void	my_mlx_pixel_put(t_struct *slg, int x, int y, int color)
{
	char *dst;

	dst = slg->addr + (y * slg->line_length + x * (slg->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_struct *slg)
{
	(void)slg;
	printf("step: %d\n", keycode);
	return (keycode);
}

int	f_close(int keycode, t_struct *slg)
{
	// (void)slg;

	if (keycode == 53)
	{
		printf("Exit\n");
		mlx_destroy_window(slg->mlx_ptr, slg->mlx_win);
		exit(0);
	}
	play(slg); // переписывает координаты игрока

	
	mlx_clear_window(slg->mlx_ptr, slg->mlx_win);
	draw(slg, '0');
	draw_image(slg, slg->p_y, slg->p_x, 0x0000FFCC); // draw player
	
	mlx_put_image_to_window(slg->mlx_ptr, slg->mlx_win, slg->img, 0, 0);
	return (0);
}

void	minilibx(t_struct *slg)
{
	// t_data		img;

	slg->mlx_ptr = mlx_init();
	slg->mlx_win = mlx_new_window(slg->mlx_ptr, 1100, 500, "so_long");
	
	
	slg->img = mlx_new_image(slg->mlx_ptr, 1100, 500);

	slg->addr = mlx_get_data_addr(slg->img, &slg->bits_per_pixel, &slg->line_length, &slg->endian);
	mlx_key_hook(slg->mlx_win, key_hook, &slg);
	draw(slg, '0'); // draw map
	draw_image(slg, slg->p_y, slg->p_x, 0x0000FFCC); // draw player
	mlx_put_image_to_window(slg->mlx_ptr, slg->mlx_win, slg->img, 0, 0); //
	mlx_hook(slg->mlx_win, 2, 1L<<0, f_close, &slg); // поток
	mlx_loop(slg->mlx_ptr);
}