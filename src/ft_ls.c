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

int		g_flags;

void			print_error(char const *name)
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	perror(name);
}

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
	{
		ret = ls_dir(".") || ret;
	}
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
			ret = print_directory(files, false);
		if (files && dirs)
			ft_putchar('\n');
		if (dirs)
			ret = print_all_dirs(dirs) || ret;
	}
	return (ret);
}

static void		sort_args(int argc, char **argv)
{
	char	*swap;
	_Bool	sorted;
	int		i;

	sorted = false;
	while (sorted == false)
	{
		sorted = true;
		i = 0;
		while (i + 1 < argc)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				sorted = false;
				swap = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = swap; 
			}
			i++;
		}
	}
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
	if (parse_flags(&argc, &argv) == -1)
		return (1);
	if (argc > 0 && ft_strcmp(argv[0], "--") == 0)
	{
		argc--;
		argv++;
	}
	if (g_flags & FLAG_NOSORT)
		g_flags = g_flags | FLAG_ALL;
	sort_args(argc, argv);
	ret = arg_to_entry(argc, argv, &files, &dirs);
	entry_lst_sort(&files);
	entry_lst_sort(&dirs);
	ret = ls_args(argc, files, dirs) || ret;
	lstdel(&files, &free_entry_mask);
	lstdel(&dirs, &free_entry_mask);
	return (ret);
}
