/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:52:42 by mburson           #+#    #+#             */
/*   Updated: 2016/12/02 18:52:45 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

static _Bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	end = ft_strlen(s) - 1;
	while (is_whitespace(s[start]))
		start++;
	while (is_whitespace(s[end]) && end > 0)
		end--;
	if (start >= end)
		return (ft_strdup("\0"));
	if (!(new = (char*)malloc(end - start + 2)))
		return (NULL);
	ft_strncpy(new, &(s[start]), end - start + 1);
	new[end - start + 1] = '\0';
	return (new);
}
