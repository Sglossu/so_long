#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			i;
	unsigned char	*m_buf1;
	unsigned char	*m_buf2;

	m_buf1 = (unsigned char *)buf1;
	m_buf2 = (unsigned char *)buf2;
	i = 0;
	while (count > 0)
	{
		if (m_buf1[i] != m_buf2[i])
			return (m_buf1[i] - m_buf2[i]);
		i++;
		count--;
	}
	return (0);
}