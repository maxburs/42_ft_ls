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
#include <sys/types.h> //struct dirent
#include <libft.h> //t_list
#include <ft_ls.h> // parse_args()
#include <dirent.h> // opendir(), readdir()


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