/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:18:43 by mburson           #+#    #+#             */
/*   Updated: 2017/01/11 22:18:44 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include <string.h>
#include <libft.h>

/*
** writes a string of wide characters to the standard output
*/

void	ft_putstrw(const wchar_t *str)
{
	write(1, str, sizeof(wchar_t) * ft_strlenw(str));
}
