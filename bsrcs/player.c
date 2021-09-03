#include "so_long_bonus.h"

void	real_draw_player(t_struct *slg, char *relative_path, int i, int j)
{
	int		img_width;
	int		img_height;

	
	slg->img.img = mlx_xpm_file_to_image(slg->img.mlx_ptr, relative_path, &img_width, &img_height);

	mlx_put_image_to_window(slg->img.mlx_ptr, slg->img.mlx_win, slg->img.img, i * (slg->scale - 1), j * (slg->scale - 1));
	if (slg->img.img == NULL)
	{
		ft_putstr_fd("error/n", 1);
		exit (-1);
	}
}

int	animation(t_struct *slg)
{
	
	if (slg->count_img > 3000 && slg->ani == 0)
	{
		slg->img.player_cur = slg->img.player_l;
		slg->count_img = 0;
		slg->ani = 1;
		mlx_destroy_image(slg->img.mlx_ptr, slg->img.img);
		draw(slg);
	}
	if (slg->count_img > 3000 && slg->ani == 1)
	{
		slg->img.player_cur = slg->img.player_r;
		slg->count_img = 0;
		slg->ani = 0;
		mlx_destroy_image(slg->img.mlx_ptr, slg->img.img);
		draw(slg);
	}
	slg->count_img++;
	return (1);
}