#include <so_long.h>

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

static	void	valid_argc_argv(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		errors();
	str = argv[1];
	while (*str != '.' && *str)
		str++;
	if (ft_strcmp(str, ".ber") != 0)
		errors();
}

void	errors(void)
{
	printf("Error\n");
	exit (-1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_struct	slg;

	slg.valid = 1;
	slg = init_struct(slg);
	valid_argc_argv(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		errors();
	read_and_valid(&slg, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		errors();
	reading_in_buf(&slg, fd);
	close(fd);
	// draw_tab(&slg);
	minilibx(&slg);
	exit(0);
	return (0);
}
