/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:09:07 by mburson           #+#    #+#             */
/*   Updated: 2017/01/04 21:09:09 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdlib.h>

char				*directory_append(char *dir_path, char *name)
{
	size_t	l;
	char	*path;
	char	*ptr;

	l = ft_strlen(dir_path) + ft_strlen(name) + 1;
	if (!(path = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	path[l] = '\0';
	ptr = ft_strplace(path, dir_path);
	ptr[1] = '/';
	ft_strplace(ptr + 2, name);
	return (path);
}
