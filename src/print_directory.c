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
#include <sys/stat.h> // struct stat
#include <sys/types.h> //struct dirent, struct passwd, struct group
#include <libft.h> //t_list
#include <ft_ls.h> // parse_args()
#include <dirent.h> // opendir(), readdir()
#include <stdint.h>
#include <pwd.h> // getpwuid()
#include <grp.h> // getgrgid()
#include <uuid/uuid.h> // getgrgid()
#include <time.h> // ctime()
#include <stdlib.h> // free()

static void		print_permissions(mode_t mode)
{
	ft_putchar(S_ISDIR(mode) ? 'd' : '-');
	ft_putchar(mode & S_IRUSR ? 'r' : '-');
	ft_putchar(mode & S_IWUSR ? 'w' : '-');
	ft_putchar(mode & S_IXUSR ? 'x' : '-');
	ft_putchar(mode & S_IRGRP ? 'r' : '-');
	ft_putchar(mode & S_IWGRP ? 'w' : '-');
	ft_putchar(mode & S_IXGRP ? 'x' : '-');
	ft_putchar(mode & S_IROTH ? 'r' : '-');
	ft_putchar(mode & S_IWOTH ? 'w' : '-');
	ft_putchar(mode & S_IXOTH ? 'x' : '-');
}

static char		*get_time(struct s_entry *entry)
{
	char			*raw_time;
	char			*formatted_time;

	if (!(raw_time = ctime(&(entry->status->st_mtime))))
		return (NULL);
	formatted_time = ft_strndup(raw_time + 4, 12);
	if (formatted_time == NULL)
		perror("ft_strndup fail in get_time");
	return (formatted_time);
}

static int		print_long(t_list *dir_lst)
{
	struct s_entry	*entry;
	char			*f_time;

	while (dir_lst)
	{
		entry = dir_lst->content;
		if (entry->dirent->d_name[0] == '.' && !(g_flags & FLAG_ALL))
		{
			dir_lst = dir_lst->next;
			continue ;
		}
		//ft_printf("%10s %10hu %10s\n",
		//		entry->dirent->d_name,
		//		entry->dirent->d_reclen,
		//		entry->path);
		f_time = get_time(entry);
		print_permissions(entry->status->st_mode);
		ft_printf(" %4ju %10s %10s %12ju %s %-16s\n",
			(uintmax_t)(nlink_t)entry->status->st_nlink,
			entry->passwd->pw_name,
			entry->group->gr_name,
			(uintmax_t)(off_t)entry->status->st_size,
			f_time,
			entry->dirent->d_name);
		free(f_time);
		dir_lst = dir_lst->next;
	}
	return (0);
}

static int		print_short(t_list *dir_lst)
{
	struct s_entry	*entry;

	while (dir_lst)
	{
		entry = dir_lst->content;
		if (entry->dirent->d_name[0] == '.' && !(g_flags & FLAG_ALL))
		{
			dir_lst = dir_lst->next;
			continue ;
		}
		ft_printf("%-16s",
			entry->dirent->d_name);
		dir_lst = dir_lst->next;
	}
	ft_putchar('\n');
	return (0);
}

int				recurse_directories(t_list *dir_lst)
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
			ft_printf("recurse on path: %s\n",
				entry->path);
		dir_lst = dir_lst->next;
	}
	return (0);
}

//todo: fix error handling
int				print_directory(t_list *dir_lst)
{
	if (g_flags & FLAG_LONG)
		print_long(dir_lst);
	else
		print_short(dir_lst);
	if (g_flags & FLAG_RECURSIVE)
		recurse_directories(dir_lst);
	return (0);
}