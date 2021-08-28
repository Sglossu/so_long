#include <so_long.h>

void	my_mlx_pixel_put(t_struct *slg, int x, int y, int color)
{
	char *dst;

	dst = slg->img.addr + (y * slg->img.line_length + x * (slg->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *vars)
{
	(void)vars;
	printf("step: %d\n", keycode);
	return (keycode);
}


int	f_close(int keycode, t_struct *slg)
{
	if (keycode == ESC)
	{
		printf("Exit\n");
		// mlx_destroy_window(img->mlx_ptr, img->mlx_win);
		exit(0);
	}

	slg->but = keycode;
	// mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
	play(slg);

	// mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, slg->img.img, 0, 0);

	return (0);
}

void	minilibx(t_struct *slg)
{
	// t_data		img;

	slg->img.mlx_ptr = mlx_init();
	slg->img.mlx_win = mlx_new_window(slg->img.mlx_ptr, slg->x_len * slg->scale, slg->y_len * slg->scale, "so_long");
	
	
	// slg->img.img = mlx_new_image(slg->img.mlx_ptr, slg->x_len * slg->scale, slg->y_len * slg->scale);

	// slg->img.addr = mlx_get_data_addr(slg->img.img, &slg->img.bits_per_pixel, &slg->img.line_length, &slg->img.endian);
	// mlx_key_hook(img.mlx_win, key_hook, &slg);

	draw(slg); // draw map
	// draw_image(slg, slg->p_y, slg->p_x, 0x0000FFCC); // draw player

	

	// mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, slg->img.img, 0, 0); //
	mlx_hook(slg->img.mlx_win, 2, 0, f_close, slg); // поток
	mlx_loop(slg->img.mlx_ptr);
}