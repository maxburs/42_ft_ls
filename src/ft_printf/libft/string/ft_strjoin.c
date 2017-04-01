/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:14:00 by mburson           #+#    #+#             */
/*   Updated: 2016/12/02 17:14:02 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*new;

	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	new[l] = '\0';
	ft_strplace(ft_strplace(new, s1) + 1, s2);
	return (new);
}
