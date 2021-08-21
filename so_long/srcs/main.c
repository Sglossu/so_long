#include "../includes/so_long.h"

// static	t_struct	init_fline(t_struct slg, int len)
// {
// 	int		fd;
// 	int		i;
// 	char	buff[len + 1];

// 	i = 0;
// 	buff[len] = '\0';
// 	fd = open(slg.filename, O_RDONLY);
// 	read(fd, &buff[0], len);
// 	close(fd);
// 	while (ft_digit(&buff[i]) > 0)
// 		i++;
// 	if (i < (len - 3) && !(slg.valid = 0))
// 		return (bsq);
// 	slg.full = buff[len - 1];
// 	slg.obs = buff[len - 2];
// 	slg.emp = buff[len - 3];
// 	buff[len - 3] = '\0';
// 	slg.y_len = atoi_s(&buff[0]);
// 	if (bsq.full == bsq.obs || bsq.full == bsq.emp || bsq.obs == bsq.emp)
// 		bsq.valid = 0;
// 	return (bsq);
// }

// static	t_struct	reader_fline(t_struct slg, int fd)
// {
// 	char	buff;
// 	int		i;
// 	int		len;

// 	len = 0;
// 	i = read(fd, &buff, 1);
// 	while (i > 0)
// 	{
// 		if (buff == '\n')
// 			break ;
// 		len++;
// 		i = read(fd, &buff, 1);
// 	}
// 	close(fd);
// 	if (i > 0 && len >= 4)
// 		slg = init_fline(slg, len);
// 	else
// 		slg.valid = 0;
// 	return (slg);
// }

// static	t_struct	read_and_valid(t_struct slg, int fd)
// {
// 	slg = reader_fline(slg, fd);
// }

static	int	valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C' \
		|| line[i] == 'E' || line[i] == 'P')
			i++;
		else
			return (-1);
	}
	return (1);
}

static	t_struct read_and_valid(t_struct slg, int fd)
{
	int		i;
	char	*line;
	int		j;

	j = 0;
	line = NULL;
	i = get_next_line(fd, &line);
	slg.x_len = ft_strlen(line);
	while (i >= -1)
	{
		if (ft_strlen(line) != slg.x_len)
			slg.valid = 0;
		if (valid_char(line) > 0)
			j++;
		else
			slg.valid = 0; // error
		if (!slg.valid)
			return (slg);
		slg.y_len++;
		i = get_next_line(fd, &line);
		if (i == 0)
			i = -1;
	}
	free(line);
	return (slg);
}

int	main()
{
	int			fd;
	t_struct	slg;

	slg.valid = 1;
	slg = init_struct(slg);
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		slg.valid = -1;
	if (slg.valid)
		slg = read_and_valid(slg, fd);
	if (!slg.valid) // error
		ft_putstr_fd("map error\n", 1);
	else
		ft_putstr_fd("all right!\n", 1);
	return (1);
}