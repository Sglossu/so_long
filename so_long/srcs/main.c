#include <so_long.h>

// static	void	free_al(t_struct *slg)
// {
// 	int		i;

// 	i = 0;
// 	while (slg->tab[i])
// 		free(slg->tab[i++]);
// 	free(slg->tab);
// }

// static	void	draw_tab(t_struct *slg)
// {
// 	int	i;

// 	i = 0;
// 	while (slg->tab[i])
// 	{
// 		printf("%s\n", slg->tab[i]);
// 		i++;
// 	}
// }

int	main(void)
{
	int			fd;
	t_struct	slg;

	slg.valid = 1;
	slg = init_struct(slg);

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		slg.valid = 0;
	if (slg.valid)
		slg = read_and_valid(slg, fd);
	close(fd);
	
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		slg.valid = 0;
	reading_in_buf(&slg, fd);

	if (!slg.valid)
		ft_putstr_fd("error\n", 1);

	close(fd);

	// draw_tab(&slg);
	if (slg.valid)
		minilibx(&slg);

	exit(0);
	// free_al(&slg);
	return (0);
}