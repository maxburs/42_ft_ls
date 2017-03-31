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
#include <stdlib.h>

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

	if (dir_lst == NULL)
		return (1);
	while (dir_lst)
	{
		entry = dir_lst->content;
		if (should_recurse(dir_lst->content))
		{
				ft_putchar('\n');
			ft_printf("%s:\n", ((struct s_entry*)(dir_lst->content))->path);
			ls_dir(entry->path);
		}
		dir_lst = dir_lst->next;
	}
	return (0);
}

static char				*directory_append(char *dir_path, char *name)
{
	size_t	l;
	char	*path;
	char	*ptr;

	l = ft_strlen(dir_path) + ft_strlen(name) + 1;
	if (!(path = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	path[l] = '\0';
	ptr = ft_strplace(path, dir_path);
	ptr[1] = '/';
	ft_strplace(ptr + 2, name);
	return (path);
}

static struct s_entry	*build_entry(struct dirent *dirent, char *dir_path)
{
	struct s_entry	*entry;

	if (NULL == (entry = (struct s_entry*)malloc(sizeof(struct s_entry))))
	{
		return (NULL);
	}
	ft_bzero(entry, sizeof(struct s_entry));
	if (NULL == (entry->path = directory_append(dir_path, dirent->d_name)))
	{
		free_entry(entry);
		return (NULL);
	}
	entry->name = ft_strdup(dirent->d_name);
	if (-1 == entry_get_meta(entry))
	{
		free_entry(entry);
		return (NULL);
	}
	return (entry);
}

static t_list		*get_dir_info(char *path)
{
	DIR				*dirp;
	struct dirent	*dir_cur;
	t_list			*dir_lst;
	struct s_entry	*entry;

	dir_lst = NULL;
	errno = 0;
	if ((dirp = opendir(path)) == NULL)
		return (NULL);
	while ((dir_cur = readdir(dirp)))
	{
		if (errno || (NULL == (entry = build_entry(dir_cur, path))))
		{
			lstdel(&dir_lst, &free);
			return (NULL);
		}
		if (entry->name[0] == '.' && !(g_flags & FLAG_ALL))
			free_entry(entry);
		else
			lstadd(&dir_lst, lstnew(entry));
	}
	if (-1 == closedir(dirp))
		lstdel(&dir_lst, &free);
	return (dir_lst);
}

int				ls_dir(char *path)
{
	t_list	*dir_lst;

	if ((dir_lst = get_dir_info(path)) == NULL && errno)
	{
		print_error(path);
		return (1);
	}
	if (entry_lst_sort(&dir_lst)
		|| print_directory(dir_lst, true)
		|| ((g_flags & FLAG_RECURSIVE) && recurse_directories(dir_lst)))
	{
		lstdel(&dir_lst, &free_entry_mask);
		return (1);
	}
	lstdel(&dir_lst, &free_entry_mask);
	return (0);
}
