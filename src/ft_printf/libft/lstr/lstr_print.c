/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:24 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 16:05:26 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	lstr_print(t_lstr *link)
{
	if (!link)
	{
		ft_putstr("(null list)\n");
		return ;
	}
	while (link)
	{
		ft_putchar('[');
		if (link->str)
			ft_putstr(link->str);
		else
			ft_putstr("NULL");
		ft_putstr("]");
		if (link->constant)
			ft_putstr(" (c)");
		else
			ft_putstr(" (m)");
		link = link->next;
		if (link)
		{
			ft_putstr(" -> ");
		}
	}
	ft_putchar('\n');
}
