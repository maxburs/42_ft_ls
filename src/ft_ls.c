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

int		g_flags;

/*
** TODO: look into handling symoblic links with lstat()
** TODO: listxattr() get extented attributes, what do i need them for?
** TODO: look into whatever S and T are in the permissions
** TODO: when username or groupname do
*/

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

int				ls_path(char *path)
{
	t_list	*dir_lst;

	if (!(dir_lst = get_dir_info(path)))
	{
		return (-1);
	}
	if (dir_lst_sort(&dir_lst)
		|| print_directory(dir_lst)
		|| ((g_flags & FLAG_RECURSIVE) && recurse_directories(dir_lst)))
	{
		lstdel(&dir_lst, &free_entry_mask);
		return (-1);
	}
	lstdel(&dir_lst, &free_entry_mask);
	return (0);
}

int				path_exists(char const *path)
{
	DIR				*dirp;

	if ((dirp = opendir(path)) == NULL)
	{
		return (false);
	}
	closedir(dirp);
	return (true);
}

int				ls_args(int argc, char **argv)
{
	int		retv;

	retv = 0;
	while (argc)
	{
		argc--;
		if (path_exists(argv[argc]))
			ft_printf("%s:\n", argv[argc]);
		else
		{
			ft_printf("ls: %s: %s\n", argv[argc], strerror(errno));
			retv = 1;
			continue ;
		}
		if (ls_path(argv[argc]))
			retv = 1;
	}
	return (retv);
}

int				main(int argc, char **argv)
{
	int		i;

	g_flags = 0;
	if (parse_flags(argc, argv, &i))
		return (0);
	if (g_flags & FLAG_NOSORT)
		g_flags = g_flags | FLAG_ALL;
	if (i == argc)
		return (ls_path("."));
	else
		return (ls_args(argc - i, argv + i));
}
