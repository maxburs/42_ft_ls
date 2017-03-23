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
		return (1);
	}
	if (dir_lst_sort(&dir_lst)
		|| print_directory(dir_lst)
		|| ((g_flags & FLAG_RECURSIVE) && recurse_directories(dir_lst)))
	{
		lstdel(&dir_lst, &free_entry_mask);
		return (1);
	}
	lstdel(&dir_lst, &free_entry_mask);
	return (0);
}

static int		path_exists(char const *path)
{
	DIR				*dirp;

	if ((dirp = opendir(path)) == NULL)
	{
		return (false);
	}
	closedir(dirp);
	return (true);
}

static int		ls_args(t_list *valid_paths)
{
	int		retv;

	retv = 0;
	while (valid_paths)
	{
		ft_printf("%s:\n", (char*)valid_paths->content);
		if (ls_path((char*)valid_paths->content))
			retv = 1;
		valid_paths = valid_paths->next;
		if (valid_paths)
			ft_putchar('\n');
	}
	return (retv);
}

int				validate_paths(int argc, char **argv, t_list **ret)
{
	int		i;
	int		error;
	t_list	*valid_paths;

	i = 0;
	error = 0;
	valid_paths = NULL;
	while (i < argc)
	{
		if (path_exists(argv[i]))
			lstpush(&valid_paths, lstnew(argv[i]));
		else
		{
			ft_printf("ls: %s: %s\n", argv[i], strerror(errno));
			argv[i] = NULL;
			error = 1;
		}
		i++;
	}
	*ret = valid_paths;
	return (error);
}

static void		nothing(void *nothing)
{
	(void)(nothing);
}

static _Bool	compare_names(void *entry1, void *entry2)
{
	if (ft_strcmp((char*)entry1, (char*)entry2) > 0)
		return (true);
	return (false);
}

int				main(int argc, char **argv)
{
	int		flg_arg_cnt;
	t_list	*valid_paths;
	int		ret;

	ret = 0;
	g_flags = 0;
	if (parse_flags(argc, argv, &flg_arg_cnt))
		return (0);
	if (g_flags & FLAG_NOSORT)
		g_flags = g_flags | FLAG_ALL;
	ret = validate_paths(argc - flg_arg_cnt, argv + flg_arg_cnt, &valid_paths);
	lstsort(&valid_paths, &compare_names);
	if (flg_arg_cnt == argc)
		ret = ls_path(".") || ret;
	else if (flg_arg_cnt + 1 == argc && valid_paths)
		ret = ls_path(argv[flg_arg_cnt]) || ret;
	else
		ret = ls_args(valid_paths) || ret;
	lstdel(&valid_paths, &nothing);
	return (ret);
}
