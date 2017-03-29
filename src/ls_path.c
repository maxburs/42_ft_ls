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

static _Bool		should_recurse(struct s_entry *entry)
{
	return (S_ISDIR(entry->status->st_mode)
			&& !(entry->name[0] == '.' && !(g_flags & FLAG_ALL))
			&& (ft_strcmp(entry->name, ".") != 0)
			&& (ft_strcmp(entry->name, "..") != 0));
}

static int			recurse_directories(t_list *dir_lst)
{
	struct s_entry	*entry;
	_Bool			has_printed;

	if (dir_lst == NULL)
		return (1);
	has_printed = false;
	while (dir_lst)
	{
		entry = dir_lst->content;
		if (should_recurse(dir_lst->content))
		{
			if (has_printed)
				ft_putchar('\n');
			ft_printf("%s:\n", ((struct s_entry*)(dir_lst->content))->path);
			ls_dir(entry->path);
			has_printed = true;
		}
		dir_lst = dir_lst->next;
	}
	return (0);
}

int				ls_dir(char *path)
{
	t_list	*dir_lst;

	if ((dir_lst = get_dir_info(path)) == NULL && errno)
	{
		ft_putstr_fd("ls: ", STDERR_FILENO);
		perror(path);
		return (1);
	}
	if (entry_lst_sort(&dir_lst)
		|| print_directory(dir_lst)
		|| ((g_flags & FLAG_RECURSIVE) && recurse_directories(dir_lst)))
	{
		lstdel(&dir_lst, &free_entry_mask);
		return (1);
	}
	lstdel(&dir_lst, &free_entry_mask);
	return (0);
}
