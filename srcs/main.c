/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:16:12 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 22:00:56 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		errors();
	close(fd);
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
	minilibx(&slg);
	exit(0);
	return (0);
}
