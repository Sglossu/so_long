/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:15:52 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 21:45:00 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	int	ft_button(t_struct *slg, int y, int x)
{
	if (slg->tab[y][x] == 'C')
	{
		slg->tab[y][x] = '0';
		slg->cltb--;
	}
	if (slg->tab[y][x] == 'E' && !slg->cltb)
	{
		printf("You are win!\n");
		exit (0);
	}
	if (slg->tab[y][x] == 'V')
	{
		printf("You are loser!\n");
		exit (0);
	}
	if (slg->tab[y][x] == '0')
	{
		slg->next_button = '0';
		slg->tab[y][x] = 'P';
		slg->tab[slg->p_y][slg->p_x] = '0';
		return (1);
	}
	return (0);
}

static	void	if_next_button_is_empty(t_struct *slg)
{
	if (slg->next_button == '0')
	{
		slg->next_button = '\0';
		mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
		draw(slg);
		slg->step++;
		printf("step %d\n", slg->step);
	}
}

void	play(t_struct *slg)
{
	if (slg->but == W)
	{
		if (ft_button(slg, slg->p_y - 1, slg->p_x) == 1)
			slg->p_y--;
	}
	else if (slg->but == S)
	{
		if (ft_button(slg, slg->p_y + 1, slg->p_x) == 1)
			slg->p_y++;
	}
	else if (slg->but == A)
	{
		if (ft_button(slg, slg->p_y, slg->p_x - 1) == 1)
			slg->p_x--;
	}
	else if (slg->but == D)
	{
		if (ft_button(slg, slg->p_y, slg->p_x + 1) == 1)
			slg->p_x++;
	}
	if_next_button_is_empty(slg);
}
