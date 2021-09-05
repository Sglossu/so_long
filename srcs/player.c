/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:15:49 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 17:15:50 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_struct *slg)
{
	if (slg->count_img > 3000 && slg->ani == 0)
	{
		slg->img.player_cur = slg->img.player_open;
		slg->count_img = 0;
		slg->ani = 1;
		draw(slg);
	}
	if (slg->count_img > 3000 && slg->ani == 1)
	{
		slg->img.player_cur = slg->img.player_close;
		slg->count_img = 0;
		slg->ani = 0;
		draw(slg);
	}
	slg->count_img++;
	return (1);
}
