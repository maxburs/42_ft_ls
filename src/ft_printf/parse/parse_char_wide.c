/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_wide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:06:03 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:21 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wchar.h>
#include <stdarg.h>
#include <ft_printf.h>

char		*parse_char_wide(va_list *ap)
{
	return ((char*)(ft_utf_32_8((wint_t)va_arg(*ap, wint_t))));
}
