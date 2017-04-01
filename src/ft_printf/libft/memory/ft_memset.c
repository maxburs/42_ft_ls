/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:04:17 by mburson           #+#    #+#             */
/*   Updated: 2016/11/28 13:04:20 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	character;
	size_t			i;

	character = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = character;
		i++;
	}
	return (b);
}
