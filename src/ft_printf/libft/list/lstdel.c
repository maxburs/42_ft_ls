/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:07:33 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 17:07:35 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	recurse_me(t_list **alst, void (*del)(void *))
{
	if ((*alst)->next)
		recurse_me(&((*alst)->next), del);
	lstdelone(alst, del);
}

void	lstdel(t_list **alst, void (*del)(void *))
{
	if (*alst == NULL)
		return ;
	recurse_me(alst, del);
}
