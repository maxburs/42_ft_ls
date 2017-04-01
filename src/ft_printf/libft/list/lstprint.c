/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:24 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 16:05:26 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	lstprint(t_list *link)
{
	if (!link)
	{
		ft_putstr("(null list)\n");
		return ;
	}
	while (link)
	{
		ft_putchar('[');
		if (link->content)
			ft_putstr(link->content);
		else
			ft_putstr("NULL");
		ft_putstr("]");
		link = link->next;
		if (link)
		{
			ft_putstr(" -> ");
		}
	}
	ft_putchar('\n');
}
