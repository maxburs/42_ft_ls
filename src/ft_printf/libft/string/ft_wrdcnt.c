/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:55:46 by mburson           #+#    #+#             */
/*   Updated: 2016/12/05 15:55:47 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_wrdcnt(const char *str, char split)
{
	size_t	count;

	count = 0;
	if (*str != split)
	{
		count++;
	}
	while (*str)
	{
		if (*str == split && str[1] != split && str[1])
		{
			count++;
			str++;
		}
		str++;
	}
	return (count);
}
