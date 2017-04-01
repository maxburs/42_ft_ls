/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:43:31 by mburson           #+#    #+#             */
/*   Updated: 2016/11/30 16:43:39 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s1[i] && i < size)
		i++;
	j = 0;
	k = i;
	while (s2[j])
	{
		if (i < size - 1)
		{
			s1[i] = s2[j];
			i++;
		}
		j++;
		k++;
	}
	if (i < size && j)
		s1[i] = '\0';
	return (k);
}
