#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t l)
{
	unsigned int	i;
	unsigned int	len_dst;
	unsigned int	k;
	unsigned int	p;

	len_dst = ft_strlen(dst);
	p = len_dst;
	i = 0;
	if (l == 0)
		return (ft_strlen(src));
	if (len_dst >= l)
		return (ft_strlen(src) + l);
	k = l - len_dst;
	while ((i < k - 1) && src[i] != '\0')
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (p + ft_strlen(src));
}
