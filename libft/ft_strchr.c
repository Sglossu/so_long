#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[i] == '\0' && c != '\0')
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)str + i);
	return (NULL);
}
