/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:06:09 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:48 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>
#include <stdlib.h>
#include <stdbool.h>

char		*parse_ptr(va_list *ap)
{
	void	*ptr;
	char	*str1;
	char	*str2;

	ptr = (void*)va_arg(*ap, void*);
	str1 = ft_itoa_base((uintmax_t)ptr, 16, false);
	format_precision(1, &str1);
	str2 = ft_strjoin("0x", str1);
	free(str1);
	return (str2);
}
