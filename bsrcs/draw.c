#include <so_long_bonus.h>

static	void	my_mlx_image_to_win(t_struct *slg, void *img_ptr, int i, int j)
{
	mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, \
	img_ptr, i * (slg->scale), j * (slg->scale));
}

static	void	some_cndtns_f_while(t_struct *slg, int i, int j)
{
	if (slg->tab[j][i] == '1')
	{
		my_mlx_image_to_win(slg, slg->img.back, i, j);
		my_mlx_image_to_win(slg, slg->img.wall, i, j);
	}
	else if (slg->tab[j][i] == '0')
		my_mlx_image_to_win(slg, slg->img.back, i, j);
	else if (slg->tab[j][i] == 'C')
	{
		my_mlx_image_to_win(slg, slg->img.back, i, j);
		my_mlx_image_to_win(slg, slg->img.thing, i, j);
	}
	else if (slg->tab[j][i] == 'P')
	{
		my_mlx_image_to_win(slg, slg->img.back, i, j);
		my_mlx_image_to_win(slg, slg->img.player_cur, i, j);
	}
	else if (slg->tab[j][i] == 'E')
	{
		my_mlx_image_to_win(slg, slg->img.back, i, j);
		my_mlx_image_to_win(slg, slg->img.exit, i, j);
	}
}

void	draw(t_struct *slg)
{
	int		i;
	int		j;
	char	*str_strjoin;
	char	*str_itoa;

	str_itoa = ft_itoa(slg->step);
	if (!str_itoa)
		errors();
	str_strjoin = ft_strjoin("step: ", str_itoa);
	if (!str_strjoin)
		errors();
	mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
	j = 0;
	while (j < slg->y_len)
	{
		i = 0;
		while (i < slg->x_len)
		{
			some_cndtns_f_while(slg, i, j);
			if (slg->tab[j][i] == 'V')
			{
				my_mlx_image_to_win(slg, slg->img.back, i, j);
				my_mlx_image_to_win(slg, slg->img.enemy, i, j);
			}
			i++;
		}
		j++;
	}
	mlx_string_put(slg->img.mlx_ptr, slg->img.mlx_win, 25, \
	slg->y_len * slg->scale -25, 0x00003153, str_strjoin);
}
