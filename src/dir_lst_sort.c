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

#include <ft_ls.h>
#include <libft.h>
#include <stdbool.h>
#include <sys/stat.h> // struct stat
#include <sys/types.h> //struct dirent, struct passwd, struct group
#include <dirent.h> // opendir(), readdir()

static _Bool	compare_names(struct s_entry *entry1, struct s_entry *entry2)
{
	if (ft_strcmp((char*)(entry1->dirent->d_name),
				(char*)(entry2->dirent->d_name)) > 0)
		return (true);
	return (false);
}

//TODO: -t is currently broken, why is that??
static _Bool	compare_time(struct s_entry *entry1, struct s_entry *entry2)
{
	if (entry1->status->st_mtime < entry2->status->st_mtime)
		return (true);
	return (false);
}

static int		bubble_sort(t_list **dir_lst, _Bool (compare)(struct s_entry*, struct s_entry*))
{
	t_list	*swap;
	t_list	**link;
	_Bool	sorted;

	sorted = false;
	while (sorted == false)
	{
		sorted = true;
		link = dir_lst;
		while (*link && (*link)->next)
		{
			if (compare((*link)->content, (*link)->next->content))
			{
				sorted = false;
				swap = (*link)->next;
				(*link)->next = swap->next;
				swap->next = (*link);
				(*link) = swap;
			}
			link = &((*link)->next);
		}
	}
	return (0);
}

int		dir_lst_sort(t_list **dir_lst)
{
	(void)(dir_lst);
	if (g_flags & FLAG_NOSORT) //TODO: reverse order
		return (0);
	bubble_sort(dir_lst, &compare_names);
	if (g_flags & FLAG_MODTIME)
		bubble_sort(dir_lst, &compare_time);
	return (0);
}