#include <so_long_bonus.h>

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

void	next_button(t_struct *slg)
{
	if (slg->next_button == '0')
	{
		// mlx_destroy_image(slg->img.mlx_ptr, slg->img.wall);
		mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
		draw(slg);
		// mlx_string_put(slg->img.mlx_ptr, slg->img.mlx_win, 25, slg->y_len * slg->scale -25, 0x00FFFFFF,  ft_strjoin("step: ", ft_itoa(slg->step)));
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
		init_player_struct_a(slg);
		if (ft_button(slg, slg->p_y, slg->p_x - 1) == 1)
			slg->p_x--;
	}
	else if (slg->but == D)
	{
		init_player_struct_d(slg);
		if (ft_button(slg, slg->p_y, slg->p_x + 1) == 1)
			slg->p_x++;
	}
	next_button(slg);
}