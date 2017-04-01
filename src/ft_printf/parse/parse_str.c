/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:07:06 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:07:23 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <string.h>
#include <ft_printf.h>
#include <stdbool.h>

static char		*parse_char_bitwise(char c, t_conv *conv)
{
	char	*str;

	str = ft_itoa_base((unsigned char)c, 2, true);
	format_precision(conv->precision, &str);
	return (str);
}

static char		*parse_str_alt(char *str, t_conv *conv)
{
	t_lstr	*l;

	l = NULL;
	while (*str)
	{
		lstr_add(&l, parse_char_bitwise(*str, conv), false);
		str++;
		if (str)
			lstr_add(&l, " ", true);
	}
	return (lstr_finish(&l));
}

char			*parse_str(t_conv *conv, va_list *ap)
{
	char *str;

	str = (char*)va_arg(*ap, char*);
	if (!str)
		return (ft_strdup("(null)"));
	else if (conv->flags & HASH_FLAG)
		return (parse_str_alt(str, conv));
	else
		return (ft_strdup(str));
}
