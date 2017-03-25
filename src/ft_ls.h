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

# include <sys/stat.h>
# include <sys/types.h>
# include <libft.h>

extern int	g_flags;

# define FLAGS_INDEX	"vlRartf1"

# define FLAG_VERBOSE	0x1
# define FLAG_LONG		0x2
# define FLAG_RECURSIVE	0x4
# define FLAG_ALL		0x8
# define FLAG_REVERSE	0X10
# define FLAG_MODTIME	0x20
# define FLAG_NOSORT	0x40
# define FLAG_ONEPERLN	0x80

struct		s_entry
{
	struct stat		*status;
	struct passwd	*passwd;
	struct group	*group;
	char			*path;
	char			*name;
	_Bool			dir;
	char			*link_path;
};

int			parse_flags(int argc, char **argv, int *paths_start);
t_list		*get_dir_info(char *path);
int			print_directory(t_list *dir_lst);
int			dir_lst_sort(t_list **dir_lst);
int			print_long(t_list *dir_lst);
int			print_short(t_list *dir_lst);
int			ls_dir(char *path);
int			build_entry_meta(struct s_entry *entry);
int			open_paths(int argc, char **argv, t_list **files, t_list **dirs);
int			ls_entry(struct s_entry *entry);
int			recurse_directories(t_list *dir_lst, _Bool first);

/*
** ./src/free.c
*/

void		free_entry_mask(void *content);
void		free_entry(struct s_entry *entry);

#endif
