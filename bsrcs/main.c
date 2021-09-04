#include <so_long_bonus.h>

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

static	void	valid_arguments(t_struct *slg, int argc, char **argv)
{
	if (argc != 2)
		slg->valid = 0;
}

int	main(int argc, char **argv)
{
	int			fd;
	t_struct	slg;

	slg.valid = 1;
	slg = init_struct(slg);
	valid_arguments(&slg, argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		slg.valid = 0;
	if (slg.valid)
		slg = read_and_valid(slg, fd);
	close(fd);
	if (!slg.valid)
	{
		ft_putstr_fd("Error1\n", 1);
		exit (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		slg.valid = 0;
	reading_in_buf(&slg, fd);
	if (!slg.valid)
		ft_putstr_fd("Error2\n", 1);
	close(fd);
	// draw_tab(&slg);
	if (slg.valid)
		minilibx(&slg);
	// free (slg.name_map);
	exit(0);
	return (0);
}