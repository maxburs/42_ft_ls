/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:02:26 by mburson           #+#    #+#             */
/*   Updated: 2016/11/29 14:02:30 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	character;

	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == character)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
