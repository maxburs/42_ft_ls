/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:30:30 by mburson           #+#    #+#             */
/*   Updated: 2016/12/02 19:30:32 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>

static size_t	plength(const char *str, char split)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != split)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!(new = (char**)malloc(sizeof(char*) * (ft_wrdcnt(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = plength(&(s[i]), c);
			if (!(new[j] = (char*)malloc(sizeof(char) * (len + 1))))
				return (NULL);
			ft_strncpy(new[j], &(s[i]), len);
			new[j][len] = '\0';
			i += len - 1;
			j++;
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}
