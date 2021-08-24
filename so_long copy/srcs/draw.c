#include <so_long.h>

void	draw_image(t_data *img, int i, int j, int color)
{
	int	x;
	int	y;
	int scale = 20;

	i *= scale;
	j *= scale;
	y = 0;
	while (y++ < scale)
	{
		x = 0;
		while (x++ < scale)
			my_mlx_pixel_put(img, x + i, y + j, color);
	}
}

void	draw(t_struct *slg, t_data *img, char c)
{
	int	i;
	int	j;

	
	slg->tab[slg->p_y][slg->p_x] = c;
	j = 0;
	while (j < slg->y_len)
	{
		i = 0;
		while (i < slg->x_len)
		{
			if (slg->tab[j][i] == '1')
				draw_image(img, i, j, 0x00FF0000);
			if (slg->tab[j][i] == '0')
				draw_image(img, i, j, 0x00003300);
			if (slg->tab[j][i] == 'C')
				draw_image(img, i, j, 0x00009933);
			if (slg->tab[j][i] == 'P')
				draw_image(img, i, j, 0x0000FFCC);	
			if (slg->tab[j][i] == 'E')
				draw_image(img, i, j, 0x000066FF);	
			i++;
		}
		j++;
	}
}
