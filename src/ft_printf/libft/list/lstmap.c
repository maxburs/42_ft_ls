/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:10:57 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 18:10:58 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

static	void	recurse_me(t_list *lst,\
					t_list *(*f)(t_list *elem), t_list **new)
{
	if (lst)
	{
		*new = f(lst);
		recurse_me(lst->next, f, &((*new)->next));
	}
	else
		*new = NULL;
}

t_list			*lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = NULL;
	recurse_me(lst, f, &new);
	return (new);
}
