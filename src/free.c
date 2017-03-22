/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:09:07 by mburson           #+#    #+#             */
/*   Updated: 2017/01/04 21:09:09 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_ls.h>
#include <libft.h>
#include <grp.h>

void	free_entry_mask(void *content)
{
	free_entry((struct s_entry *)content);
}

void	free_entry(struct s_entry *entry)
{
	if (entry == NULL)
		return ;
	ft_memdel((void**)&entry->dirent);
	ft_memdel((void**)&entry->status);
	ft_memdel((void**)&entry->passwd);
	ft_memdel((void**)&entry->group);
	ft_memdel((void**)&entry);
}
