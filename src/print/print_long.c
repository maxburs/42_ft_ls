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
	struct s_widths		widths;

	ft_bzero(&widths, sizeof(widths));
	entry_long_wwidths(entry, &widths);
	return (0);
}

int					print_dir_long(t_list *dir_lst, _Bool print_total)
{
	struct s_widths		*widths;

	widths = find_widths(dir_lst);
	if (dir_lst && print_total)
		ft_printf("total %ju\n", get_blocks(dir_lst));
	while (dir_lst)
	{
		entry_long_wwidths(dir_lst->content, widths);
		dir_lst = dir_lst->next;
	}
	free(widths);
	return (0);
}
