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

static _Bool			should_treat_link_as_dir(struct s_entry *entry)
{
	struct stat		status;

	ft_bzero(&status, sizeof(status));
	if (false == S_ISLNK(entry->status->st_mode)
		||  (g_flags & FLAG_LONG)
		|| -1 == stat(entry->path, &status))
		return (false);
	return (S_ISDIR(status.st_mode));
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
	if (-1 == entry_get_meta(entry))
	{
		free_entry(entry);
		return (NULL);
	}
	if (path[ft_strlen(path) - 1] == '/'
		|| S_ISDIR(entry->status->st_mode)
		|| should_treat_link_as_dir(entry))
	{
		entry->dir = true;
	}
	if (entry->dir == true)
		entry->name = name_from_path(path);
	else
		entry->name = ft_strdup(path);
	if (NULL == entry->name)
	{
		free_entry(entry);
		return (NULL);
	}
	return (entry);
}

int				arg_to_entry(int argc, char **argv,
											t_list **files, t_list **dirs)
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
			print_error(argv[i]);
			argv[i] = NULL;
			error = 1;
		}
		i++;
	}
	return (error);
}
