#include <so_long_bonus.h>

static	int	valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C' \
		|| line[i] == 'E' || line[i] == 'P' || line[i] == 'V')
			i++;
		
		else
			return (-1);
	}
	return (1);
}

static	void	first_end_lines(t_struct *slg, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			slg->valid = 0;
		i++;
	}
}

static	void	other_lines(t_struct *slg, char *line, int i)
{
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		errors();
	while (line[i])
	{
		if (line[i] == '0')
			slg->emp = '0';
		else if (line[i] == '1')
			slg->wall = '1';
		else if (line[i] == 'C')
			slg->thg = 'C';
		else if (line[i] == 'E')
			slg->exit = 'E';
		else if (line[i] == 'V')
			slg->enemy = 'V';
		else if (line[i] == 'P')
		{
			if (slg->plr)
				slg->flag = 0;
			else
				slg->plr = 'P';
		}
		i++;
	}
}

static	void	valid_gnl(t_struct *slg, char **line, int i, int j)
{
	if (ft_strlen(*line) != slg->x_len)
		slg->valid = 0;
	if (valid_char(*line) > 0)
		j++;
	else
		errors();
	if (!slg->valid)
		errors();
	if ((i == 0 || !slg->y_len) && slg->valid)
		first_end_lines(slg, *line);
	else
	{
		other_lines(slg, *line, 1);
	}
}

void	read_and_valid(t_struct *slg, int fd)
{
	int		i;
	char	*line;
	int		j;

	j = 0;
	line = NULL;
	i = get_next_line(fd, &line);
	slg->x_len = ft_strlen(line);
	while (i >= 0 && *line != '\0')
	{
		valid_gnl(slg, &line, i, j);
		slg->y_len++;
		free(line);
		i = get_next_line(fd, &line);
	}
	if (!slg->emp || !slg->wall || !slg->thg || !slg->exit || !slg->plr \
	|| !slg->enemy || !slg->flag)
		errors();
	free(line);
}
