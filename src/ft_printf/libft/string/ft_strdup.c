/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:30:54 by mburson           #+#    #+#             */
/*   Updated: 2016/11/29 17:30:56 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <string.h>
#include <errno.h>

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
