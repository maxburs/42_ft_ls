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

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h> // struct stat
#include <sys/types.h> //struct dirent, struct passwd, struct group
#include <libft.h> //t_list

extern int	g_flags;

# define FLAGS_INDEX	"vlRartf"

# define FLAG_VERBOSE	0x1
# define FLAG_LONG		0x2
# define FLAG_RECURSIVE	0x4
# define FLAG_ALL		0x8
# define FLAG_REVERSE	0X10
# define FLAG_MODTIME	0x20
# define FLAG_NOSORT	0x40

struct      s_entry
{
	struct dirent	*dirent;
	struct stat		*status;
	struct passwd	*passwd;
	struct group	*group;
	char			*path;
};

_Bool		parse_args(int argc, char **argv, char **path);
t_list		*get_dir_info(char *path);
int			print_directory(t_list *dir_lst);
int			ls_path(char *path);
int			dir_lst_sort(t_list **dir_lst);
int			print_long(t_list *dir_lst);

#endif