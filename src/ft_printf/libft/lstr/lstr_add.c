/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:50:17 by mburson           #+#    #+#             */
/*   Updated: 2017/01/13 01:50:18 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

_Bool		lstr_add(t_lstr **start, char *str, _Bool constant)
{
	t_lstr	*link;

	if (!*start)
	{
		if (!(*start = lstr_new(str, constant)))
			return (false);
		return (true);
	}
	link = (*start);
	while (link->next)
		link = link->next;
	if (!(link->next = lstr_new(str, constant)))
		return (false);
	return (true);
}
