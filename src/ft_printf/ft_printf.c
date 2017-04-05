/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:15:48 by mburson           #+#    #+#             */
/*   Updated: 2016/12/21 19:15:49 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

/*
** b conversion character: print an integers bits
** TODO: may no longer be norm
*/

static int		handle_null_c(t_conv *conv, char *str)
{
	if (conv->letter == 'c' && !*str)
	{
		write(1, "", 1);
		if (conv->min_width)
			conv->min_width -= 1;
		return (1);
	}
	return (0);
}

static int		print_arg(char *str)
{
	int		len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

static int		handle_conv(const char **format, va_list *ap)
{
	t_conv	conv;
	char	*str;
	_Bool	null_print;

	build_conv(format, &conv);
	if (!conv.letter)
	{
		ft_putstr_fd("BUILD CONV ERROR", 0);
		return (0);
	}
	inference(&conv, ap);
	if (!(str = parse(&conv, ap)))
	{
		ft_putstr_fd("PARSE ERROR", 0);
		return (0);
	}
	null_print = handle_null_c(&conv, str);
	if (!(str = format_str(&conv, str)))
	{
		ft_putstr_fd("FORMAT ERROR", 0);
		return (0);
	}
	return (print_arg(str) + null_print);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			length;

	length = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			length += handle_conv(&format, &ap);
		}
		else
		{
			write(1, format, 1);
			format++;
			length++;
		}
	}
	va_end(ap);
	return (length);
}
