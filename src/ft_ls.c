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
#include <ft_ls.h> // parse_args(), get_dir_info(), print_directory()
#include <string.h> // NULL
#include <libft.h> // ft_strdel() t_list

int		g_flags;

int				ls_path(char *path)
{
	t_list	*dir_lst;

	if (!(dir_lst = get_dir_info(path)))
		return (1);
	print_directory(dir_lst);
	//TODO: free dir_lst
	return (0);
}

int				main(int argc, char **argv)
{
	char	*path;

	g_flags = 0;
	path = NULL;
	if (parse_args(argc, argv, &path)
		|| (ls_path(path)))
	{
		ft_strdel(&path);
		return (0);
	}
	return (0);
}