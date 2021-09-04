#include <so_long_bonus.h>

// void	draw_image(t_struct *slg, int i, int j, int color)
// {
// 	int	x;
// 	int	y;

// 	i *= slg->scale;
// 	j *= slg->scale;
// 	y = 0;
// 	while (y < slg->scale)
// 	{
// 		x = 0;
// 		while (x < slg->scale)
// 		{
// 			my_mlx_pixel_put(slg, x + i, y + j, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	real_draw(t_struct *slg, char *relative_path, int i, int j)
// {
// 	int		img_width;
// 	int		img_height;

	
// 	slg->img.img = mlx_xpm_file_to_image(slg->img.mlx_ptr, relative_path, &img_width, &img_height);

// 	mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, slg->img.img, i * (slg->scale - 1), j * (slg->scale - 1));
// }

void	my_mlx_put_image_to_window(t_struct *slg, void *img_ptr, int i, int j)
{
	mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, img_ptr, i * (slg->scale), j * (slg->scale));
}

void	draw_back(t_struct *slg)
{
	int	i;
	int	j;

	j = 0;
	while (j < slg->y_len)
	{
		i = 0;
		while (i < slg->x_len)
		{
			my_mlx_put_image_to_window(slg, slg->img.back, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_struct *slg)
{
	int	i;
	int	j;

	// draw_back(slg);
	mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
	j = 0;
	while (j < slg->y_len)
	{
		i = 0;
		while (i < slg->x_len)
		{
			if (slg->tab[j][i] == '1')
			{
				my_mlx_put_image_to_window(slg, slg->img.back, i, j);
				my_mlx_put_image_to_window(slg, slg->img.wall, i, j);
			}
			else if (slg->tab[j][i] == '0')
				my_mlx_put_image_to_window(slg, slg->img.back, i, j);
			else if (slg->tab[j][i] == 'C')
			{
				my_mlx_put_image_to_window(slg, slg->img.back, i, j);
				my_mlx_put_image_to_window(slg, slg->img.thing, i, j);
			}
			else if (slg->tab[j][i] == 'P')
			{
				my_mlx_put_image_to_window(slg, slg->img.back, i, j);
				my_mlx_put_image_to_window(slg, slg->img.player_cur, i, j);
			}
			else if (slg->tab[j][i] == 'E')
			{
				my_mlx_put_image_to_window(slg, slg->img.back, i, j);
				my_mlx_put_image_to_window(slg, slg->img.exit, i, j);
			}
			else if (slg->tab[j][i] == 'V')
			{
				my_mlx_put_image_to_window(slg, slg->img.back, i, j);
				my_mlx_put_image_to_window(slg, slg->img.enemy, i, j);
			}
			i++;
		}
		j++;
	}
	// mlx_destroy_image(slg->img.mlx_ptr, slg->img.exit);
	// mlx_destroy_image(slg->img.mlx_ptr, slg->img.exit);
}
