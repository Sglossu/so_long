/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:28:01 by sglossu           #+#    #+#             */
/*   Updated: 2021/09/05 19:28:44 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned int	i;

	i = 0;
	while ((unsigned char)str1[i] != '\0' && (unsigned char)str2[i] != '\0')
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if ((unsigned char)str1[i] != '\0' || (unsigned char)str2[i] != '\0')
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
