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

static	void	valid_arguments(t_struct *slg, int argc, char **argv)
{
	if (argc != 2)
		slg->valid = 0;
	else
	{
		slg->name_map = (char *)malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
		if (slg->name_map == NULL)
		{
			slg->valid = 0;
			return;
		}
		slg->name_map = argv[1];
		printf("%s\n", slg->name_map);
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_struct	slg;

	slg.valid = 1;
	slg = init_struct(slg);

	valid_arguments(&slg, argc, argv);
	fd = open(slg.name_map, O_RDONLY);
	if (fd < 0)
		slg.valid = 0;
	if (slg.valid)
		slg = read_and_valid(slg, fd);
	close(fd);
	
	fd = open(slg.name_map, O_RDONLY);
	if (fd < 0)
		slg.valid = 0;
	reading_in_buf(&slg, fd);

	if (!slg.valid)
		ft_putstr_fd("error4\n", 1);

	close(fd);

	// draw_tab(&slg);
	if (slg.valid)
		minilibx(&slg);

	exit(0);
	// free_al(&slg);
	return (0);
}