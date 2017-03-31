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
	ft_printf("%s\n", entry->name);
	return (0);
}

int				print_dir_short(t_list *dir_lst)
{
	if (dir_lst == NULL)
		return (0);
	while (true)
	{
		ft_putstr(((struct s_entry*)dir_lst->content)->name);
		dir_lst = dir_lst->next;
		if (dir_lst)
			g_flags & FLAG_ONEPERLN ? ft_putchar('\n') : ft_putstr("\n");
		else
			break ;
	}
	ft_putchar('\n');
	return (0);
}

int				print_directory(t_list *dir_lst, _Bool print_total)
{
	if (g_flags & FLAG_LONG)
	{
		if (print_dir_long(dir_lst, print_total))
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
