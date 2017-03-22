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

#include <ft_printf.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libft.h>
#include <ft_ls.h>
#include <dirent.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <stdlib.h>


static int		print_short(t_list *dir_lst)
{
	struct s_entry	*entry;

	while (dir_lst)
	{
		entry = dir_lst->content;
		if (entry->dirent->d_name[0] == '.' && !(g_flags & FLAG_ALL))
		{
			dir_lst = dir_lst->next;
			continue ;
		}
		ft_printf("%-16s",
			entry->dirent->d_name);
		dir_lst = dir_lst->next;
	}
	ft_putchar('\n');
	return (0);
}

static int		recurse_directories(t_list *dir_lst)
{
	struct s_entry	*entry;

	while (dir_lst)
	{
		entry = dir_lst->content;
		if ((entry->dirent->d_name[0] == '.' && !(g_flags & FLAG_ALL))
			|| (ft_strcmp(entry->dirent->d_name, ".") == 0)
			|| (ft_strcmp(entry->dirent->d_name, "..") == 0))
		{
			dir_lst = dir_lst->next;
			continue ;
		}
		if (entry->status->st_mode & S_IFDIR)
		{
			ft_printf("\n%s:\n", entry->path);
			ls_path(entry->path);
		}
		dir_lst = dir_lst->next;
	}
	return (0);
}

int				print_directory(t_list *dir_lst)
{
	if (g_flags & FLAG_LONG)
	{
		if (print_long(dir_lst))
			return (-1);
	}
	else
	{
		if (print_short(dir_lst))
			return (-1);
	}
	if (g_flags & FLAG_RECURSIVE)
		return (recurse_directories(dir_lst));
	else
		return (0);
}
