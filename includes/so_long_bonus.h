#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*player_cur;
	char		*player_r;
	char		*player_l;
}				t_data;

typedef struct	s_struct
{
	char	**tab;
	int		x_len;
	int		y_len;
	char	emp;
	char	wall;
	char	thg;
	char	exit;
	char	plr;
	int		valid;
	int		flag;
	int		enemy;
	int		but;
	int		scale;
	int		p_x;
	int		p_y;
	char	c;
	int		cltb;
	int		step;
	t_data	img;
	char	*name_map;
	int		ani;
	int		count_img;
}				t_struct;

t_struct	init_struct(t_struct slg);
void		init_player_struct_d(t_struct *slg);
void		init_player_struct_a(t_struct *slg);
t_struct	read_and_valid(t_struct slg, int fd);
void		reading_in_buf(t_struct *slg, int fd);
void		minilibx(t_struct *slg);
void		draw(t_struct *slg);

void		my_mlx_pixel_put(t_struct *slg, int x, int y, int color);
void		play(t_struct *slg);
int			key_hook(int keycode, t_data *vars);
void		draw_image(t_struct *slg, int i, int j, int color);
void		set_image(t_struct *slg,  int i, int j);
int			animation(t_struct *slg);

#endif