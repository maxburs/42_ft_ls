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
#include <sys/stat.h>
#include <sys/types.h>
#include <libft.h>
#include <ft_ls.h>
#include <dirent.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

static char			file_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISSOCK(mode))
		return ('s');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISBLK(mode))
		return ('b');
	return ('!');
}

static void			print_permissions(mode_t mode)
{
	ft_putchar(file_type(mode));
	ft_putchar(mode & S_IRUSR ? 'r' : '-');
	ft_putchar(mode & S_IWUSR ? 'w' : '-');
	if (mode & S_ISUID)
		ft_putchar(mode & S_IXUSR ? 's' : 'S');
	else
		ft_putchar(mode & S_IXUSR ? 'x' : '-');
	ft_putchar(mode & S_IRGRP ? 'r' : '-');
	ft_putchar(mode & S_IWGRP ? 'w' : '-');
	if (mode & S_ISGID)
		ft_putchar(mode & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(mode & S_IXGRP ? 'x' : '-');
	ft_putchar(mode & S_IROTH ? 'r' : '-');
	ft_putchar(mode & S_IWOTH ? 'w' : '-');
	if (mode & S_ISVTX)
		ft_putchar(mode & S_IXOTH ? 't' : 'T');
	else
		ft_putchar(mode & S_IXOTH ? 'x' : '-');
}

#define SIXMONTHS ((365/2) * 86400)  

static _Bool		within_six_months(time_t time1, time_t time2)
{
	return (time1 < SIXMONTHS + time2 && time2 > SIXMONTHS + time1);
}

static char			*get_time(struct s_entry *entry)
{
	char		*raw_time;
	char		*formatted_time;
	time_t		current_time;

	current_time = time(NULL);
	if (current_time == -1)
		return (NULL);
	if (!(raw_time = ctime(&(entry->status->st_mtime))))
		return (NULL);
	formatted_time = ft_strndup(raw_time + 4, 12);
	if (formatted_time == NULL)
		return (NULL);
	if (within_six_months(entry->status->st_mtime, current_time))
		ft_strncpy(formatted_time + 7, raw_time + 19, 5);
	return (formatted_time);
}

static uintmax_t	get_blocks(t_list *dir_lst)
{
	uintmax_t	blocks;

	blocks = 0;
	while (dir_lst)
	{
		if (!(((struct s_entry*)dir_lst->content)->name[0] == '.'
				&& !(g_flags & FLAG_ALL)))
			blocks += ((struct s_entry*)dir_lst->content)->status->st_blocks;
		dir_lst = dir_lst->next;
	}
	return (blocks);
}


int					print_entry_long(struct s_entry *entry)
{
	char			*f_time;

	f_time = get_time(entry);
	print_permissions(entry->status->st_mode);
	ft_printf(" %4ju %10s %10s",
		(uintmax_t)(nlink_t)entry->status->st_nlink,
		entry->passwd->pw_name,
		entry->group->gr_name);
	if (S_ISBLK(entry->status->st_mode) || S_ISCHR(entry->status->st_mode))
	{
		ft_printf(" %8ju %8ju", (uintmax_t)major(entry->status->st_rdev),
								(uintmax_t)minor(entry->status->st_rdev));
	}
	else
	{
		ft_printf(" %16ju", (uintmax_t)(off_t)entry->status->st_size);
	}
	ft_printf(" %s %s", f_time, entry->name);
	if (entry->link_path)
		ft_printf(" -> %s", entry->link_path);
	ft_putchar('\n');
	free(f_time);
	return (0);
}


int					print_dir_long(t_list *dir_lst)
{
	if (dir_lst)
		ft_printf("total %ju\n", get_blocks(dir_lst));
	while (dir_lst)
	{
		print_entry_long(dir_lst->content);
		dir_lst = dir_lst->next;
	}
	return (0);
}
