/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 22:04:52 by mburson           #+#    #+#             */
/*   Updated: 2016/10/31 22:04:55 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t index;

	index = 0;
	while (index < len && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index < len)
	{
		while (index < len && dest[index] != '\0')
		{
			dest[index] = '\0';
			index++;
		}
	}
	return (dest);
}
