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
#include <ft_printf.h>
#include <string.h>

static _Bool	parse_flags_string(char *parse_me)
{
	int		i;

	while (*parse_me)
	{
		i = ft_strchri(FLAGS_INDEX, *parse_me);
		if (i == -1)
		{
			ft_printf("ls: illegal option -- %c\n", *parse_me);
			ft_printf("usage: ls [-%s] [file ...]\n", FLAGS_INDEX);
			return (1);
		}
		g_flags += 1 << i;
		parse_me++;
	}
	return (0);
}

int				parse_flags(int argc, char **argv, int *paths_start)
{
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (parse_flags_string(argv[i] + 1))
			return (-1);
		i++;
	}
	*paths_start = i;
	if (g_flags & FLAG_VERBOSE)
		ft_printf(" flags: %b\n", g_flags);
	return (0);
}
