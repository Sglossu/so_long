#include "../includes/so_long.h"

static	t_struct	memory_al(t_struct bsq)
{
	int		i;

	i = 0;
	bsq.tab = (char**)malloc(sizeof(char*) * bsq.y_len + 1);
	bsq.tab[bsq.y_len] = NULL;
	while (i < bsq.y_len)
	{
		bsq.tab[i] = (char*)malloc(sizeof(char) * bsq.x_len + 1);
		bsq.tab[i][bsq.x_len] = '\0';
		i++;
	}
	return (bsq);
}

t_struct			array(t_struct bsq)
{
	int		i;
	int		j;
	int		fd;
	char	buff;

	i = 0;
	buff = '\0';
	bsq = memory_al(bsq);
	fd = open(bsq.filename, O_RDONLY);
	while (buff != '\n')
		read(fd, &buff, 1);
	read(fd, &buff, 1);
	while (i < bsq.y_len)
	{
		j = 0;
		while (buff != '\n')
		{
			bsq.tab[i][j++] = buff;
			read(fd, &buff, 1);
		}
		read(fd, &buff, 1);
		i++;
	}
	close(fd);
	return (bsq);
}
