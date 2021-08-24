#include <so_long.h>

static	void	ft_w(t_struct *slg)
{
	slg->tab[slg->p_y + 1][slg->p_x] = 'P';
	slg->tab[slg->p_y][slg->p_x] = '0';
	slg->p_y++;
}

static	void	ft_s(t_struct *slg)
{
	slg->tab[slg->p_y - 1][slg->p_x] = 'P';
	slg->tab[slg->p_y][slg->p_x] = '0';
	slg->p_y--;
}

static	void	ft_a(t_struct *slg)
{
	slg->tab[slg->p_y][slg->p_x - 1] = 'P';
	slg->tab[slg->p_y][slg->p_x] = '0';
	slg->p_x--;
}

static	void	ft_d(t_struct *slg)
{
	slg->tab[slg->p_y][slg->p_x + 1] = 'P';
	slg->tab[slg->p_y][slg->p_x] = '0';
	slg->p_x++;
}

void	play(t_struct *slg)
{
	slg->but = mlx_key_hook(slg->mlx_win, key_hook, &slg);
	if (slg->but == W)
		ft_w(slg);
	else if (slg->but == S)
		ft_s(slg);
	else if (slg->but == A)
		ft_a(slg);
	else if (slg->but == D)
		ft_d(slg);	
}