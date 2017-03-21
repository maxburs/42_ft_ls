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

void		print_permissions(mode_t mode)
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

int		print_directory(t_list *dir_lst)
{
	struct s_entry	*entry;

	while (dir_lst)
	{
		entry = dir_lst->content;
		ft_printf("%10s %10hu %10s\n",
				entry->dirent->d_name,
				entry->dirent->d_reclen,
				entry->path);
		print_permissions(entry->status->st_mode);
		ft_putchar('\n');
		dir_lst = dir_lst->next;
	}
	return (0);
}