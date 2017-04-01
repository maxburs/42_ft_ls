/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:05:57 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:02 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <libft.h>
#include <ft_printf.h>

static char		*parse_char_alt(char c)
{
	char	*str;

	str = ft_itoa_base((unsigned char)c, 10, true);
	format_precision(3, &str);
	return (str);
}

static char		*parse_char_reg(char c)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[1] = '\0';
	str[0] = c;
	return (str);
}

char			*parse_char(t_conv *conv, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (conv->flags & HASH_FLAG)
		return (parse_char_alt(c));
	else
		return (parse_char_reg(c));
}
