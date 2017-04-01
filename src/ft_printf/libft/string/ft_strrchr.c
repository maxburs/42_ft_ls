/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:37:43 by mburson           #+#    #+#             */
/*   Updated: 2016/11/30 17:37:46 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	character;
	size_t	i;
	size_t	last;
	_Bool	found;

	found = 0;
	character = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == character)
		{
			last = i;
			found = 1;
		}
		i++;
	}
	if (s[i] == character)
		return (char*)(s + i);
	if (found)
		return (char*)(s + last);
	return (NULL);
}
