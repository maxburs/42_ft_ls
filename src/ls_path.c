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
#include <ft_ls.h>
#include <string.h>
#include <libft.h>
#include <dirent.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>

int				recurse_directories(t_list *dir_lst, _Bool first)
{
	struct s_entry	*entry;

	while (dir_lst)
	{
		entry = dir_lst->content;
		if (first == false
			&& ((entry->name[0] == '.' && !(g_flags & FLAG_ALL))
			|| (ft_strcmp(entry->name, ".") == 0)
			|| (ft_strcmp(entry->name, "..") == 0)))
		{
			dir_lst = dir_lst->next;
			continue ;
		}
		if (entry->status->st_mode & S_IFDIR)
		{
			ft_printf("\n%s:\n", entry->path);
			ls_dir(entry->path);
		}
		dir_lst = dir_lst->next;
	}
	return (0);
}

int				ls_dir(char *path)
{
	t_list	*dir_lst;

	if (!(dir_lst = get_dir_info(path)))
	{
		ft_putstr_fd("ls: ", STDERR_FILENO);
		perror(path);
		return (1);
	}
	if (dir_lst_sort(&dir_lst)
		|| print_directory(dir_lst)
		|| ((g_flags & FLAG_RECURSIVE) && recurse_directories(dir_lst, false)))
	{
		lstdel(&dir_lst, &free_entry_mask);
		return (1);
	}
	lstdel(&dir_lst, &free_entry_mask);
	return (0);
}
