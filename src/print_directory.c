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
#include <stdlib.h>
#include <stdbool.h>


int				print_entry_short(struct s_entry *entry)
{
	if (entry->name[0] == '.' && !(g_flags & FLAG_ALL))
	{
		return (0);
	}
	if (g_flags & FLAG_ONEPERLN)
		ft_printf("%s\n", entry->name);
	else
		ft_printf("%-16s", entry->name);
	return (0);
}

int				print_dir_short(t_list *dir_lst)
{
	while (dir_lst)
	{
		if (-1 == print_entry_short(dir_lst->content))
			return (-1);
		dir_lst = dir_lst->next;
	}
	if ((g_flags & FLAG_ONEPERLN) == false)
		ft_putchar('\n');
	return (0);
}

int				print_directory(t_list *dir_lst)
{
	if (g_flags & FLAG_LONG)
	{
		if (print_dir_long(dir_lst))
			return (-1);
	}
	else
	{
		if (print_dir_short(dir_lst))
			return (-1);
	}
	return (0);
}

int				print_entry(struct s_entry *entry)
{
	if (g_flags & FLAG_LONG)
	{
		if (print_entry_long(entry))
			return (-1);
	}
	else
	{
		if (print_entry_short(entry))
			return (-1);
	}
	return (0);
}
