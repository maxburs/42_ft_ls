/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:07:11 by mburson           #+#    #+#             */
/*   Updated: 2016/11/01 14:07:12 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t index;
	size_t compare;

	if (!little[0])
	{
		return (char*)(big);
	}
	index = 0;
	while (index < len && big[index])
	{
		compare = 0;
		while (big[index + compare] == little[compare] && index + compare < len)
		{
			if (!little[compare + 1])
			{
				return (char*)(&big[index]);
			}
			compare++;
		}
		index++;
	}
	return (NULL);
}
