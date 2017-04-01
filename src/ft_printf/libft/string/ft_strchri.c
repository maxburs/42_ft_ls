/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:19:58 by mburson           #+#    #+#             */
/*   Updated: 2017/01/04 23:19:59 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the index of a character in a string
** if character is not found returns -1
** if string is longer than INT_MAX than behavior is undefined
*/

#include <string.h>

int		ft_strchri(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (-1);
}
