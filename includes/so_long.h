/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:17:00 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/08 23:33:44 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# define W		13
# define A		0
# define S		1
# define D		2
# define ESC 	53

typedef struct s_data
{
	void		*mlx_win;
	void		*mlx_ptr;
	void		*img;
	char		*player_cur;
	char		*player_or;
	char		*player_cr;
	char		*player_ol;
	char		*player_cl;
	char		*player_open;
	char		*player_close;
	void		*exit;
	void		*enemy;
	void		*wall;
	void		*thing;
	void		*back;
}				t_data;

typedef struct s_struct
{
	char	**tab;
	int		x_len;
	int		y_len;
	char	emp;
	char	wall;
	char	thg;
	char	exit;
	char	plr;
	int		flag;
	int		but;
	int		scale;
	int		p_x;
	int		p_y;
	char	c;
	int		cltb;
	int		step;
	t_data	img;
	int		ani;
	int		count_img;
	char	next_button;
}				t_struct;

t_struct	init_struct(t_struct slg);
void		read_and_valid(t_struct *slg, int fd);
void		reading_in_buf(t_struct *slg, int fd);
void		minilibx(t_struct *slg);
void		draw(t_struct *slg);
void		init_picture(t_struct *slg);
void		errors(void);

int			key_hook(int keycode, t_data *vars);
int			close_window(void);
int			f_close(int keycode, t_struct *slg);
void		my_mlx_pixel_put(t_struct *slg, int x, int y, int color);
void		play(t_struct *slg);
int			key_hook(int keycode, t_data *vars);

#endif