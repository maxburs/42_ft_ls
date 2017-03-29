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
** TODO: only stat() in first directory ??
** NOTE: test on /dev/
** TODO: change date format when date is farther than 6 months away
** TODO: test on files/dirs what i don't have permissions on
*/

static int		print_all_dirs(t_list *dir_lst)
{
	struct s_entry	*entry;

	if (dir_lst == NULL)
		return (1);
	while (true)
	{
		entry = dir_lst->content;
		ft_printf("%s:\n", entry->path);
		ls_dir(entry->path);
		dir_lst = dir_lst->next;
		if (dir_lst)
			ft_putchar('\n');
		else
			break ;
	}
	return (0);
}

static int		ls_args(int argc, t_list *files, t_list *dirs)
{
	int		ret;

	ret = 0;
	if (argc == 0)
		ret = ls_dir(".") || ret;
	else if (argc == 1)
	{
		if (files)
		{
			ret = print_entry(files->content) || ret;
		}
		else if (dirs)
			ret = ls_dir(((struct s_entry*)dirs->content)->path) || ret;
	}
	else
	{
		if (files)
			ret = print_directory(files);
		if (dirs)
			ret = print_all_dirs(dirs) || ret;
	}
	return (ret);
}

int				main(int argc, char **argv)
{
	t_list	*files;
	t_list	*dirs;
	int		ret;

	files = NULL;
	dirs = NULL;
	ret = 0;
	g_flags = 0;
	if (parse_flags(&argc, &argv))
		return (0);
	if (ft_strcmp(argv[0], "--") == 0)
	{
		argc--;
		argv++;
	}
	if (g_flags & FLAG_NOSORT)
		g_flags = g_flags | FLAG_ALL;
	ret = open_paths(argc, argv, &files, &dirs);
	entry_lst_sort(&files);
	entry_lst_sort(&dirs);
	ret = ls_args(argc, files, dirs) || ret;
	lstdel(&files, &free_entry_mask);
	lstdel(&dirs, &free_entry_mask);
	return (ret);
}
