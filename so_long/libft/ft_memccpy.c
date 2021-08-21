#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*m_dst;
	unsigned char	*m_src;
	size_t			i;

	m_dst = (unsigned char *)dst;
	m_src = (unsigned char *)src;
	i = 0;
	while (i != n)
	{
		m_dst[i] = m_src[i];
		if ((unsigned char)m_src[i] == (unsigned char)c)
		{
			i++;
			return (m_dst + i);
		}
		i++;
	}
	return (NULL);
}
