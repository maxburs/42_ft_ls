/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf_32_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:59:54 by mburson           #+#    #+#             */
/*   Updated: 2017/01/19 20:59:56 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <libft.h>
#include <string.h>
#include <stdlib.h>

static unsigned char	format_trailing(unsigned char c)
{
	return ((c & 0b00111111) | 0b10000000);
}

static unsigned char	format_first(unsigned char c, int length)
{
	return ((0b11110000 << (4 - length)) | c);
}

static char				get_length(wint_t c)
{
	if (!((0xFFFFFFFF << 7) & c))
		return (1);
	if (!((0xFFFFFFFF << 11) & c))
		return (2);
	if (!((0xFFFFFFFF << 16) & c))
		return (3);
	if (!((0xFFFFFFFF << 21) & c))
		return (4);
	return (0);
}

unsigned char			*ft_utf_32_8(wint_t c)
{
	unsigned char	*res;
	int				len;
	int				i;

	if (!(len = get_length(c))
		|| !(res = (unsigned char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (len == 1)
	{
		res[0] = (unsigned char)c;
		return (res);
	}
	i = len;
	while (i)
	{
		i--;
		if ((res[i] = (unsigned char)c))
		{
			res[i] = format_trailing(res[i]);
			c = c >> 6;
		}
	}
	res[i] = format_first(res[i], len);
	return (res);
}
