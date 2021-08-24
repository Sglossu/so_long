#include <so_long.h>

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *vars)
{
	(void)vars;
	printf("step: %d\n", keycode);
	return (keycode);
}

int	f_close(int keycode, t_data *img)
{
	(void)img;

	if (keycode == 53)
	{
		printf("Exit\n");
		exit(0);
		// mlx_destroy_window(img->mlx_ptr, img->mlx_win);
	}
	play(slg, &img);

	
	clear_window();
	draw map ();
	*/
	
	// mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.img, 0, 0);
	return (0);
}

void	minilibx(t_struct *slg)
{
	t_data		img;

	img.mlx_ptr = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx_ptr, 1100, 500, "so_long");
	
	
	img.img = mlx_new_image(img.mlx_ptr, 1100, 500);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(img.mlx_win, key_hook, &slg);
	draw(slg, &img, '0'); // draw map
	draw_image(&img, slg->p_y, slg->p_x, 0x0000FFCC); // draw player
	mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.img, 0, 0); //
	mlx_hook(img.mlx_win, 2, 1L<<0, f_close, &img); // поток
	mlx_loop(img.mlx_ptr);
}