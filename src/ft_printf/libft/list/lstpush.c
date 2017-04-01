/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:34:41 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 17:34:43 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** adds an element to the back of a list
*/

void	lstpush(t_list **alst, t_list *new)
{
	while (*alst)
		alst = &((*alst)->next);
	*alst = new;
}
