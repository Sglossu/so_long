/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:15:54 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 17:16:05 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
	mlx_loop(slg->img.mlx_ptr);
}
