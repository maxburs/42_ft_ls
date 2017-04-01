/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:06:12 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:17 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include <libft.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ft_printf.h>

static char		*parse_char_bitwise(wchar_t c, t_conv *conv)
{
	char	*str;

	str = ft_itoa_base((uintmax_t)c, 2, true);
	format_precision(conv->precision, &str);
	return (str);
}

static char		*alt(t_conv *conv, wchar_t *wstr)
{
	t_lstr	*l;

	l = NULL;
	while (*wstr)
	{
		lstr_add(&l, parse_char_bitwise(*wstr, conv), false);
		wstr++;
		if (wstr)
			lstr_add(&l, " ", true);
	}
	return (lstr_finish(&l));
}

static char		*reg(wchar_t *wstr)
{
	unsigned char	*c;
	t_lstr			*l;

	l = NULL;
	c = ft_utf_32_8(*wstr);
	lstr_add(&l, (char*)c, false);
	wstr++;
	while (*c)
	{
		c = ft_utf_32_8(*wstr);
		lstr_add(&l, (char*)c, false);
		wstr++;
	}
	return (lstr_finish(&l));
}

char			*parse_str_wide(t_conv *conv, va_list *ap)
{
	wchar_t			*wstr;

	wstr = va_arg(*ap, wchar_t*);
	if (conv->flags & HASH_FLAG)
		return (alt(conv, wstr));
	else
		return (reg(wstr));
}
