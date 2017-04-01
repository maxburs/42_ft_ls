/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:34:41 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 17:34:43 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

void			lstreverse(t_list **alst)
{
	t_list	*new;
	t_list	*old;
	t_list	*moving;

	old = *alst;
	new = NULL;
	while (old)
	{
		moving = old;
		old = moving->next;
		moving->next = new;
		new = moving;
	}
	*alst = new;
}
