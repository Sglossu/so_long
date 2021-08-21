#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*m_dst;

	m_dst = dst;
	i = 0;
	while (i != n)
	{
		m_dst[i] = c;
		i++;
	}
	return (m_dst);
}
