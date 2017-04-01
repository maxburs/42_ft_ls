/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:59:02 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 19:59:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <string.h>

t_lstr		*lstr_new(char *str, _Bool constant)
{
	t_lstr		*link;

	if (!(link = (t_lstr*)malloc(sizeof(t_lstr))))
		return (NULL);
	link->str = str;
	link->next = NULL;
	link->constant = constant;
	return (link);
}
