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

struct				s_entry
{
	struct stat		*status;
	struct passwd	*passwd;
	struct group	*group;
	char			*path;
	char			*name;
	_Bool			dir;
	char			*link_path;
};

struct				s_widths
{
	unsigned int	links;
	unsigned int	owner;
	unsigned int	group;
	unsigned int	blocks;
	unsigned int	major;
	unsigned int	minor;

};

int					parse_flags(int *argc, char ***argv);

/*
** ./open_paths.c
*/

void				print_error(char const *name);
int					open_paths(int argc, char **argv,
											t_list **files, t_list **dirs);

/*
** ./entry_lst_sort.c
*/

int					entry_lst_sort(t_list **dir_lst);

/*
** ./find_widths.c
*/

struct s_widths		*find_widths(t_list *dir_lst);

/*
** ./src/free.c
*/

void				free_entry_mask(void *content);
void				free_entry(struct s_entry *entry);

/*
** ./get_dir_info.c
*/

int					build_entry_meta(struct s_entry *entry);
t_list				*get_dir_info(char *path);

/*
** ./ls_path.c
*/

int					ls_dir(char *path);



/*
** ./print/
*/

int					entry_long_wwidths(struct s_entry *entry,
												struct s_widths *widths);

/*
** ./print/print_directory.c
*/

int					print_entry_short(struct s_entry *entry);
int					print_dir_short(t_list *dir_lst);
int					print_directory(t_list *dir_lst, _Bool print_total);
int					print_entry(struct s_entry *entry);

/*
** ./print/print_long.c
*/

int					print_entry_long(struct s_entry *entry);
int					print_dir_long(t_list *dir_lst, _Bool print_total);

#endif
