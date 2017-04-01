/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:18:35 by mburson           #+#    #+#             */
/*   Updated: 2017/01/05 20:18:37 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>
#include <string.h>

char			*parse(t_conv *conv, va_list *ap)
{
	if (conv->letter == 's' || conv->letter == 'S')
	{
		if (conv->length == L_LENGTH || conv->letter == 'S')
			return (parse_str_wide(conv, ap));
		else
			return (parse_str(conv, ap));
	}
	else if (ft_strchr("dDiuUoOxXb", conv->letter))
	{
		return (parse_int(conv, ap));
	}
	else if (conv->letter == 'c' || conv->letter == 'C')
	{
		if (conv->length == L_LENGTH || conv->letter == 'C')
			return (parse_char_wide(ap));
		else
			return (parse_char(conv, ap));
	}
	else if (conv->letter == 'p')
		return (parse_ptr(ap));
	else if (conv->letter == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}
