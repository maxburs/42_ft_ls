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

static void			update_if_larger(struct s_widths *widths,
												struct s_entry *entry)
{
	unsigned int	size;

	size = (unsigned int)ft_numlen_un(entry->status->st_nlink, 10);
	if (size > widths->links)
		widths->links = size;
	size = (unsigned int)ft_strlen(entry->passwd->pw_name);
	if (size > widths->owner)
		widths->owner = size;
	size = (unsigned int)ft_strlen(entry->group->gr_name);
	if (size > widths->group)
		widths->group = size;
	if (S_ISBLK(entry->status->st_mode) || S_ISCHR(entry->status->st_mode))
	{
		size = (unsigned int)ft_numlen_un(major(entry->status->st_rdev), 10);
		if (size > widths->major)
			widths->major = size;
		size = (unsigned int)ft_numlen_un(minor(entry->status->st_rdev), 10);
		if (size > widths->minor)
			widths->minor = size;
	}
	else
	{
		size = (unsigned int)ft_numlen_un(entry->status->st_size, 10);
		if (size > widths->blocks)
			widths->blocks = size;
	}
}

struct s_widths		*find_widths(t_list *dir_lst)
{
	struct s_widths		*widths;

	if (NULL == (widths = (struct s_widths*)malloc(sizeof(struct s_widths))))
		return (NULL);
	ft_bzero(widths, sizeof(struct s_widths));
	while (dir_lst)
	{
		update_if_larger(widths, dir_lst->content);
		dir_lst = dir_lst->next;
	}
	if (widths->major + widths->minor + 1 > widths->blocks)
		widths->blocks = widths->major + widths->minor + 1;
	return (widths);
}
