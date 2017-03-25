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

static char				*name_from_path(char const *path)
{
	char const	*ptr;
	char const	*last;

	ptr = path;
	last = NULL;
	while ((ptr = ft_strchr(path, '/')))
	{
		last = ptr;
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
		perror("malloc error in open_paths/build_entry");
		return (NULL);
	}
	ft_bzero(entry, sizeof(struct s_entry));
	entry->path = ft_strdup(path);
	if (NULL == (entry->name = name_from_path(path)))
	{
		perror("error in name_from_path");
		free_entry(entry);
		return (NULL);
	}
	if (-1 == build_entry_meta(entry))
	{
		free_entry(entry);
		return (NULL);
	}
	if (entry->name[0] == '\0' || entry->status->st_mode & S_IFDIR)
	{
		entry->dir = true;
		ft_strdel(&entry->name);
		//TODO: free name?
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
			//TODO: needs to go to stderror
			ft_printf("ls: %s: %s\n", argv[i], strerror(errno));
			argv[i] = NULL;
			error = 1;
		}
		i++;
	}
	return (error);
}
