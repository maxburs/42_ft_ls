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
#include <stdlib.h>
#include <unistd.h>

/*
** extract the filename from a path
** if path ends in a '/' returns "\0"
*/

static char				*name_from_path(char const *path)
{
	char const	*ptr;
	char const	*last;

	ptr = path;
	last = NULL;
	while ((ptr = ft_strchr(ptr, '/')) && ptr[1])
	{
		last = ptr;
		ptr++;
	}
	if (last == NULL)
		return (ft_strdup(path));
	else
		return (ft_strdup(last + 1));
}

static struct s_entry	*build_entry(char const *path)
{
	struct s_entry	*entry;

	if (NULL == (entry = (struct s_entry*)malloc(sizeof(struct s_entry))))
	{
		return (NULL);
	}
	ft_bzero(entry, sizeof(struct s_entry));
	entry->path = ft_strdup(path);
	if (NULL == (entry->name = name_from_path(path)))
	{
		free_entry(entry);
		return (NULL);
	}
	if (-1 == build_entry_meta(entry))
	{
		free_entry(entry);
		return (NULL);
	}
	if (entry->name[ft_strlen(entry->name) - 1] == '/'
		|| entry->status->st_mode & S_IFDIR
		|| (S_ISLNK(entry->status->st_mode && (g_flags & FLAG_ALL))))
	{
		entry->dir = true;
	}
	return (entry);
}

int				open_paths(int argc, char **argv, t_list **files, t_list **dirs)
{
	int				i;
	int				error;
	struct s_entry	*entry;

	i = 0;
	error = 0;
	while (i < argc)
	{
		if (NULL != (entry = build_entry(argv[i])))
		{
			if (entry->dir)
				lstadd(dirs, lstnew(entry));
			else
				lstadd(files, lstnew(entry));
		}
		else
		{
			ft_putstr_fd("ls: ", STDERR_FILENO);
			perror(argv[i]);
			argv[i] = NULL;
			error = 1;
		}
		i++;
	}
	return (error);
}
