/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:28:11 by mburson           #+#    #+#             */
/*   Updated: 2016/12/15 17:14:28 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <errno.h>

/*
** creates a new string from char *str of n length and null terminates it
*/

char				*ft_strndup(const char *str, size_t n)
{
	char	*new_str;

	if (!(new_str = (char*)malloc(sizeof(char) * (n + 1))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	new_str[n] = '\0';
	while (n)
	{
		n--;
		new_str[n] = str[n];
	}
	return (new_str);
}
