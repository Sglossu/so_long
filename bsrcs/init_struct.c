/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:27:45 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 17:27:46 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

t_struct	init_struct(t_struct slg)
{
	slg.x_len = 0;
	slg.y_len = 0;
	slg.emp = '\0';
	slg.wall = '\0';
	slg.thg = '\0';
	slg.exit = '\0';
	slg.plr = '\0';
	slg.valid = 1;
	slg.flag = 1;
	slg.scale = 10;
	slg.p_x = 0;
	slg.p_y = 0;
	slg.cltb = 0;
	slg.scale = 50;
	slg.step = 0;
	slg.ani = 0;
	slg.count_img = 0;
	slg.next_button = '\0';
	slg.but = 0;
	slg.img.player_cur = "texture/ping_right_close.xpm";
	slg.img.player_or = "texture/ping_right_open.xpm";
	slg.img.player_cr = "texture/ping_right_close.xpm";
	slg.img.player_ol = "texture/ping_left_open.xpm";
	slg.img.player_cl = "texture/ping_left_close.xpm";
	return (slg);
}

void	init_player_struct_d(t_struct *slg)
{
	slg->img.player_cur = slg->img.player_or;
	slg->img.player_open = slg->img.player_or;
	slg->img.player_close = slg->img.player_cr;
}

void	init_player_struct_a(t_struct *slg)
{
	slg->img.player_cur = slg->img.player_ol;
	slg->img.player_open = slg->img.player_ol;
	slg->img.player_close = slg->img.player_cl;
}

static	void	init_picture_two(t_struct *slg)
{
	int	img_width;
	int	img_height;

	slg->img.exit = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ice_hole.xpm", &img_width, &img_height);
	slg->img.wall = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ice.xpm", &img_width, &img_height);
	slg->img.enemy = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/sea_lion.xpm", &img_width, &img_height);
	slg->img.thing = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/heart.xpm", &img_width, &img_height);
	slg->img.back = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/back_snow.xpm", &img_width, &img_height);
	slg->img.player_cl = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_left_close.xpm", &img_width, &img_height);
	slg->img.player_ol = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_left_open.xpm", &img_width, &img_height);
}

void	init_picture(t_struct *slg)
{
	int	img_width;
	int	img_height;

	slg->img.player_cur = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_right_close.xpm", &img_width, &img_height);
	slg->img.player_open = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_right_open.xpm", &img_width, &img_height);
	slg->img.player_close = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_right_close.xpm", &img_width, &img_height);
	slg->img.player_or = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_right_open.xpm", &img_width, &img_height);
	slg->img.player_cr = mlx_xpm_file_to_image(slg->img.mlx_ptr, \
	"texture/ping_right_close.xpm", &img_width, &img_height);
	init_picture_two(slg);
	if (!slg->img.player_cur || !slg->img.exit || !slg->img.wall \
	|| !slg->img.enemy || !slg->img.thing || !slg->img.back \
	|| !slg->img.player_open || !slg->img.player_close || !slg->img.player_or \
	|| !slg->img.player_cr || !slg->img.player_ol \
	|| !slg->img.player_cl)
	{
		ft_putstr_fd("error\n", 1);
		exit (-1);
	}
}
