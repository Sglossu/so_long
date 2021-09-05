/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_in_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:15:46 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 17:15:47 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	memory_al(t_struct *slg)
{
	int		i;

	i = 0;
	slg->tab = (char **)malloc(sizeof(char *) * (slg->y_len + 1));
	slg->tab[slg->y_len] = NULL;
	while (i < slg->y_len)
	{
		slg->tab[i] = (char *)malloc(sizeof(char) * (slg->x_len + 1));
		slg->tab[i][slg->x_len] = '\0';
		i++;
	}
}

static	void	conditions_in_while(t_struct *slg, char buff, int i, int j)
{
	if (buff == 'P')
	{
		slg->p_x = j;
		slg->p_y = i;
	}
	if (buff == 'C')
		slg->cltb++;
}

void	reading_in_buf(t_struct *slg, int fd)
{
	int		i;
	int		j;
	char	buff;
	int		byte;

	i = 0;
	buff = '\0';
	memory_al(slg);
	byte = read(fd, &buff, 1);
	while (i < slg->y_len)
	{
		j = 0;
		while (buff != '\n' && byte != 0)
		{
			conditions_in_while(slg, buff, i, j);
			slg->tab[i][j] = buff;
			byte = read(fd, &buff, 1);
			j++;
		}
		read(fd, &buff, 1);
		i++;
	}
	close(fd);
}
