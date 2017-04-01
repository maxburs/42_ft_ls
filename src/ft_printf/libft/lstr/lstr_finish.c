/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:11:38 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 20:23:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>

static size_t	total_length(t_lstr *link)
{
	size_t	size;

	size = 0;
	while (link)
	{
		size += ft_strlen(link->str);
		link = link->next;
	}
	return (size);
}

char			*lstr_finish(t_lstr **start)
{
	t_lstr		*link;
	t_lstr		*link_last;
	char		*str;
	char		*cur;

	if (*start == NULL)
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(char) * (total_length(*start) + 1))))
		return (NULL);
	cur = str;
	link = *start;
	*start = NULL;
	while (link)
	{
		cur = ft_strplace(cur, (link->str));
		cur++;
		if (!(link->constant))
			free(link->str);
		link_last = link;
		link = link->next;
		free(link_last);
	}
	*cur = '\0';
	return (str);
}
