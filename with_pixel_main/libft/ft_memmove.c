#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*m_dst;
	unsigned char	*m_src;
	size_t			i;

	m_dst = (unsigned char *)dst;
	m_src = (unsigned char *)src;
	i = 0;
	if (m_dst == NULL && m_src == NULL)
		return (0);
	if (m_dst < m_src)
	{
		while (len-- > 0)
		{
			m_dst[i] = m_src[i];
			i++;
		}
	}
	else
	{
		while (++i <= len)
			m_dst[len - i] = m_src[len - i];
	}
	return (m_dst);
}
