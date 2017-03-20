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
#include <sys/types.h> //struct dirent, struct passwd, struct group
#include <dirent.h> // opendir(), readdir()
#include <stdlib.h> // malloc()

#include <sys/stat.h> // struct stat
#include <unistd.h> // stat()

#include <stdbool.h> // true, false

#include <pwd.h> // getpwuid()
#include <grp.h> // getgrgid()

#include <errno.h>

static char			*directory_append(char *dir_path, char *name)
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

static struct s_entry	*build_entry(struct dirent *entry_raw, char *dir_path)
{
	struct s_entry	*entry;

	if (NULL == (entry = (struct s_entry*)malloc(sizeof(struct s_entry))))
	{
		perror("malloc error in build_entry");
		ft_memdel((void**)&entry);
		return (NULL);
	}
	if (NULL == (entry->dirent = ft_memdup(entry_raw, sizeof(struct dirent))))
	{
		perror("memdup() failure in build_entry()");
		ft_memdel((void**)&entry);
		return (NULL);
	}

	entry->path = directory_append(dir_path, entry_raw->d_name);;
	if (false == (g_flags & FLAG_LONG))
		return (entry);
	if (NULL == (entry->status = malloc(sizeof(struct stat))))
		return (NULL);
	if (-1 == stat(entry->path, entry->status))
	{
		perror("error on stat() call in build_entry()");
		return (NULL);
	}
	if (NULL == (entry->passwd = getpwuid(entry->status->st_uid)))
	{
		perror("error on getpwid() in build_entry");
		return (NULL);
	}
	if (NULL == (entry->group = getgrgid(entry->status->st_uid)))
	{
		perror("error on getpwid() in build_entry");
		return (NULL);
	}
	return (entry);
}

t_list	*get_dir_info(char *path)
{
	DIR				*dirp;
	struct dirent	*dir_cur;
	t_list			*dir_lst;

	dir_lst = NULL;
	if ((dirp = opendir(path)) == NULL)
	{
		ft_printf("ls: cannot access '%s': %s\n", path, strerror(errno));
		return (NULL);
	}
	while ((dir_cur = readdir(dirp)))
	{
		if (errno)
		{
			perror("readdir() error in recurse_me");
			lstdel(&dir_lst, &free);
			return (NULL);
		}
		lstadd(&dir_lst, lstnew(build_entry(dir_cur, path)));
	}
	closedir(dirp);
	return (dir_lst);
}
