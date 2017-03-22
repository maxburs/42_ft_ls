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

#include <ft_ls.h>
#include <libft.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

static _Bool	compare_names(void *entry1, void *entry2)
{
	if (ft_strcmp((char*)(((struct s_entry*)entry1)->dirent->d_name),
				(char*)(((struct s_entry*)entry2)->dirent->d_name)) > 0)
		return (true);
	return (false);
}

static _Bool	compare_time(void *entry1, void *entry2)
{
	if (((struct s_entry*)entry1)->status->st_mtime <
			((struct s_entry*)entry2)->status->st_mtime)
		return (true);
	return (false);
}

int				dir_lst_sort(t_list **dir_lst)
{
	if (g_flags & FLAG_NOSORT)
	{
		lstreverse(dir_lst);
		return (0);
	}
	lstsort(dir_lst, &compare_names);
	if (g_flags & FLAG_MODTIME)
		lstsort(dir_lst, &compare_time);
	return (0);
}
