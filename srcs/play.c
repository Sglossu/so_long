#include <so_long.h>

static	void	ft_s(t_struct *slg)
{
	if (slg->tab[slg->p_y + 1][slg->p_x] == 'C')
	{
		slg->tab[slg->p_y + 1][slg->p_x] = '0';
		slg->cltb--;
	}
	if (slg->tab[slg->p_y + 1][slg->p_x] == 'E' && !slg->cltb)
		exit (0);
	if (slg->tab[slg->p_y + 1][slg->p_x] == '0')
	{
		slg->tab[slg->p_y + 1][slg->p_x] = 'P';
		slg->tab[slg->p_y][slg->p_x] = '0';
		slg->p_y++;
		mlx_destroy_image(slg->img.mlx_ptr, slg->img.img);
		// mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
		// mlx_destroy_window(slg->img.mlx_ptr, slg->img.mlx_win);
		draw(slg);
		mlx_string_put(slg->img.mlx_ptr, slg->img.mlx_win, 25, slg->y_len * slg->scale -25, 0x00FFFFFF, ft_strjoin("step: ", ft_itoa(slg->step)));
		slg->step++;
		printf("step %d\n", slg->step);
	}
}

static	void	ft_w(t_struct *slg)
{
	if (slg->tab[slg->p_y - 1][slg->p_x] == 'C')
	{
		slg->tab[slg->p_y - 1][slg->p_x] = '0';
		slg->cltb--;
	}
	if (slg->tab[slg->p_y - 1][slg->p_x] == 'E' && !slg->cltb)
		exit (0);
	if (slg->tab[slg->p_y - 1][slg->p_x] == '0')
	{
		slg->tab[slg->p_y - 1][slg->p_x] = 'P';
		slg->tab[slg->p_y][slg->p_x] = '0';
		slg->p_y--;
		mlx_destroy_image(slg->img.mlx_ptr, slg->img.img);
		// mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
		// mlx_destroy_window(slg->img.mlx_ptr, slg->img.mlx_win);
		draw(slg);
		mlx_string_put(slg->img.mlx_ptr, slg->img.mlx_win, 25, slg->y_len * slg->scale -25, 0x00FFFFFF,  ft_strjoin("step: ", ft_itoa(slg->step)));
		slg->step++;
		printf("step %d\n", slg->step);
	}
}

static	void	ft_a(t_struct *slg)
{
	if (slg->tab[slg->p_y][slg->p_x - 1] == 'C')
	{
		slg->tab[slg->p_y][slg->p_x - 1] = '0';
		slg->cltb--;
	}
	if (slg->tab[slg->p_y][slg->p_x - 1] == 'E' && !slg->cltb)
		exit (0);
	if (slg->tab[slg->p_y][slg->p_x - 1] == '0')
	{
		slg->tab[slg->p_y][slg->p_x - 1] = 'P';
		slg->tab[slg->p_y][slg->p_x] = '0';
		slg->p_x--;
		mlx_destroy_image(slg->img.mlx_ptr, slg->img.img);
		// mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
		// mlx_destroy_window(slg->img.mlx_ptr, slg->img.mlx_win);
		draw(slg);
		mlx_string_put(slg->img.mlx_ptr, slg->img.mlx_win, 25, slg->y_len * slg->scale -25, 0x00FFFFFF,  ft_strjoin("step: ", ft_itoa(slg->step)));
		slg->step++;
		printf("step %d\n", slg->step);
	}
}

static	void	ft_d(t_struct *slg)
{
	if (slg->tab[slg->p_y][slg->p_x + 1] == 'C')
	{
		slg->tab[slg->p_y][slg->p_x + 1] = '0';
		slg->cltb--;
	}
	if (slg->tab[slg->p_y][slg->p_x + 1] == 'E' && !slg->cltb)
		exit (0);
	if (slg->tab[slg->p_y][slg->p_x + 1] == '0')
	{
		slg->tab[slg->p_y][slg->p_x + 1] = 'P';
		slg->tab[slg->p_y][slg->p_x] = '0';
		slg->p_x++;
		mlx_destroy_image(slg->img.mlx_ptr, slg->img.img);
		// mlx_clear_window(slg->img.mlx_ptr, slg->img.mlx_win);
		// mlx_destroy_window(slg->img.mlx_ptr, slg->img.mlx_win);
		draw(slg);
		mlx_string_put(slg->img.mlx_ptr, slg->img.mlx_win, 25, slg->y_len * slg->scale -25, 0x00FFFFFF,  ft_strjoin("step: ", ft_itoa(slg->step)));
		slg->step++;
		printf("step %d\n", slg->step);
	}
}

void	play(t_struct *slg)
{
	if (slg->but == W)
		ft_w(slg);
	else if (slg->but == S)
		ft_s(slg);
	else if (slg->but == A)
		ft_a(slg);
	else if (slg->but == D)
		ft_d(slg);
}