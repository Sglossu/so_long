#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
}				t_struct;

t_struct	init_struct(t_struct slg);

#endif