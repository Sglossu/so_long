#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t l)
{
	unsigned long	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (l == 0)
		return (ft_strlen((char *)src));
	while (i < (l - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}
