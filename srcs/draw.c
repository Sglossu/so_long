/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:16:22 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 17:16:23 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
	int	i;
	int	j;

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
}
