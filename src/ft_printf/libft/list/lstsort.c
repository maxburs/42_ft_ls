/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:16:20 by mburson           #+#    #+#             */
/*   Updated: 2017/03/22 09:05:38 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <libft.h>

void		lstsort(t_list **dir_lst, _Bool (compare)(void*, void*))
{
	t_list	*swap;
	t_list	**link;
	_Bool	sorted;

	sorted = false;
	while (sorted == false)
	{
		sorted = true;
		link = dir_lst;
		while (*link && (*link)->next)
		{
			if (compare((*link)->content, (*link)->next->content))
			{
				sorted = false;
				swap = (*link)->next;
				(*link)->next = swap->next;
				swap->next = (*link);
				(*link) = swap;
			}
			link = &((*link)->next);
		}
	}
}
