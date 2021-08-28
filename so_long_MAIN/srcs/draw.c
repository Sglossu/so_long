#include <so_long.h>

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

void	real_draw(t_struct *slg, char *relative_path, int i, int j)
{
	int		img_width;
	int		img_height;

	slg->img.img = mlx_xpm_file_to_image(slg->img.mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, slg->img.img, i * (slg->scale - 1), j * (slg->scale - 1));
	if (slg->img.img == NULL)
	{
		ft_putstr_fd("error/n", 1);
		exit (-1);
	}


}

void	draw(t_struct *slg)
{
	int	i;
	int	j;

	j = 0;
	while (j < slg->y_len)
	{
		i = 0;
		while (i < slg->x_len)
		{
			if (slg->tab[j][i] == '1')
				// draw_image(slg, i, j, 0x00FF0000);
				real_draw(slg, "texture/wall.xpm",  i, j);
			if (slg->tab[j][i] == '0')
				// draw_image(slg, i, j, 0x009999FF);
				real_draw(slg, "texture/back2.xpm",  i, j);
			if (slg->tab[j][i] == 'C')
				// draw_image(slg, i, j, 0x00000000);
				real_draw(slg, "texture/thing.xpm",  i, j);
			if (slg->tab[j][i] == 'P')
			{
				// draw_image(slg, i, j, 0x009FFF00);	
				real_draw(slg, "texture/back2.xpm", i, j);
				real_draw(slg, "texture/ALEXANDRA.xpm", i, j);
			}
			if (slg->tab[j][i] == 'E')
				// draw_image(slg, i, j, 0x00000055);	
				real_draw(slg, "texture/exit.xpm",  i, j);	
			i++;
		}
		j++;
	}
}
