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

#include <sys/stat.h>
#include <sys/types.h>

extern int	g_flags;

# define FLAGS_INDEX	"vlRart"

# define FLAG_VERBOSE	0x1
# define FLAG_LONG		0x2
# define FLAG_RECURSIVE	0x4
# define FLAG_ALL		0x8
# define FLAG_REVERSE	0X10
# define FLAG_MODTIME	0x20

struct      s_entry
{
	struct dirent	*dirent;
	struct stat		*status;
//	unsigned short	reclen;
//	unsigned char	type;
//	char			name[256];
	char			*path;
};

_Bool		parse_args(int argc, char **argv, char **path);

#endif