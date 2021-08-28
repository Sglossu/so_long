#include "libft.h"

long long	ft_atoi_long(const char *str)
{
	int			i;
	long long	minus;
	long long	nb;

	i = 0;
	minus = 1;
	nb = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i++] == 45)
			minus = -1;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
	}
	return (nb * minus);
}
