/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:28:16 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 19:28:17 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	size_t	i;
	char	*my_s;

	i = 0;
	if ((char *)s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen((char *)s))
	{
		my_s = (char *)malloc(sizeof(char));
		if (my_s == NULL)
			return (NULL);
		my_s[0] = '\0';
		return (my_s);
	}
	my_s = (char *)malloc(sizeof(char) * (len + 1));
	if (my_s == NULL)
		return (NULL);
	while ((char *)s && len--)
		my_s[i++] = s[start++];
	my_s[i] = '\0';
	return (my_s);
}
