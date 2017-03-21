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

#include <ft_ls.h> //g_flags, 
#include <libft.h> //ft_strchri()
#include <ft_printf.h> //ft_printf

static _Bool	parse_flags(char *parse_me)
{
	int		i;

	while (*parse_me)
	{
		i = ft_strchri(FLAGS_INDEX, *parse_me);
		if (i == -1)
		{
			ft_printf("\033[31merror: %c flag not found\n\033[0m", *parse_me);
			return (1);
		}
		g_flags += 1 << i;
		parse_me++;
	}
	return (0);
}
static void		parse_arg_result_print(char *path)
{
	ft_printf(" flags: %b\n", g_flags);
	ft_printf("  path: %s\n", path);
}

_Bool			parse_args(int argc, char **argv, char **path)
{
	while (--argc > 0)
	{
		if (argv[argc][0] == '-')
		{
			if (parse_flags(argv[argc] + 1))
				return (1);
		}
		else if (*path)
		{
			ft_printf("\033[31merror: path defined twice\n\033[0m");
			return (1);
		}
		else
			*path = ft_strdup(argv[argc]);
	}
	if (*path == NULL)
		*path = ft_strdup(".");
	if (g_flags & FLAG_VERBOSE)
		parse_arg_result_print(*path);
	return (0);
}