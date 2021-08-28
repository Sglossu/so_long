#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	all_size;
	void	*buf;

	all_size = count * size;
	buf = malloc(all_size);
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, all_size);
	return (buf);
}
