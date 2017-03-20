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

#include <ft_printf.h> //ft_printf()
#include <ft_ls.h> // parse_args()
#include <string.h> // NULL
#include <stdio.h> // perror

#include <libft.h> // t_list, lstadd(), lstnew()
#include <sys/types.h> //struct dirent
#include <dirent.h> // opendir(), readdir()
#include <stdlib.h> // malloc()

#include <sys/stat.h> // stat()
#include <unistd.h> // stat()

#include <stdbool.h> // true, false

#include <errno.h>

int		g_flags;

char			*directory_append(char *dir_path, char *name)
{
	size_t	l;
	char	*path;
	char	*ptr;

	if (dir_path[ft_strlen(dir_path) - 1] == '/')
		return (ft_strjoin(dir_path, name));

	l = ft_strlen(dir_path) + ft_strlen(name) + 1;
	if (!(path = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	path[l] = '\0';
	ptr = ft_strplace(path, dir_path);
	ptr[1] = '/';
	ft_strplace(ptr + 2, name);
	return (path);
}

struct s_entry	*build_entry(struct dirent *entry_raw, char *dir_path)
{
	struct s_entry	*entry;
	struct stat		*status;

	if (!(entry = (struct s_entry*)malloc(sizeof(struct s_entry))))
	{
		perror("malloc error in build_entry");
		ft_memdel((void**)&entry);
		return (NULL);
	}
	if (!(entry->dirent = ft_memdup(entry_raw, sizeof(struct dirent))))
	{
		perror("memdup() failure in build_entry()");
		ft_memdel((void**)&entry);
		return (NULL);
	}

	entry->path = directory_append(dir_path, entry_raw->d_name);;
	if ((g_flags & FLAG_LONG) == false)
		return (entry);
	if (!(status = malloc(sizeof(struct stat))))
		return (NULL);
	if (stat(entry->path, status) == -1)
	{
		perror("error on stat() call in build_entry()");
		return (NULL);
	}
	entry->status = status;
	return (entry);
}

int		print_directory(t_list *dir_lst)
{
	struct s_entry	*entry;

	while (dir_lst)
	{
		entry = dir_lst->content;
		ft_printf("%15s %15hu %15s\n", entry->dirent->d_name, entry->dirent->d_reclen, entry->path);
		dir_lst = dir_lst->next;
	}
	return (0);
}


int		recurse_me(char *path)
{
	DIR				*dirp;
	struct dirent	*dir_cur;
	t_list			*dir_lst;

	dir_lst = NULL;
	if ((dirp = opendir(path)) == NULL)
	{r
		ft_printf("ls: cannot access '%s': %s\n", path, strerror(errno));
		return (1);
	}
	while ((dir_cur = readdir(dirp)))
	{
		if (errno)
		{
			perror("readdir() error in recurse_me");
			lstdel(&dir_lst, &free);
			return (1);
		}
		lstadd(&dir_lst, lstnew(build_entry(dir_cur, path)));
	}
	closedir(dirp);
	print_directory(dir_lst);
	lstdel(&dir_lst, &free);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*path;

	g_flags = 0;
	path = NULL;
	if (parse_args(argc, argv, &path))
		return (0);
	if (recurse_me(path))
		return (0);
	return (0);
}