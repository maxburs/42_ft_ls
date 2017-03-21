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

//TODO: look into handling symoblic links with lstat()
//TODO: listxattr() get extented attributes, what do i need them for?

int				ls_path(char *path)
{
	t_list	*dir_lst;

	if (!(dir_lst = get_dir_info(path)))
		return (1);
	
	if (dir_lst_sort(&dir_lst))
		return (1);
	if (print_directory(dir_lst))
		return (1);
	//TODO: free dir_lst
	return (0);
}

int				main(int argc, char **argv)
{
	char	*path;

	g_flags = 0;
	path = NULL;
	if (parse_args(argc, argv, &path))
		return (0);
	if (g_flags & FLAG_NOSORT)
		g_flags = g_flags | FLAG_ALL;
	if ((ls_path(path)))
	{
		ft_strdel(&path);
		return (0);
	}
	return (0);
}