/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 23:58:51 by mburson           #+#    #+#             */
/*   Updated: 2017/01/26 23:58:52 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <string.h>
#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

char			*ft_strpad(char *str, size_t n, char c, _Bool back)
{
	size_t	length;
	char	*result;

	length = ft_strlen(str);
	if (!(result = (char*)malloc(sizeof(char) * (length + n + 1))))
	{
		return (NULL);
	}
	result[length + n] = '\0';
	if (back)
	{
		ft_strcpy(result, str);
		ft_memset(result + length, c, n);
	}
	else
	{
		ft_strcpy(result + n, str);
		ft_memset(result, c, n);
	}
	return (result);
}

void			format_precision(size_t precision, char **str)
{
	size_t	length;
	char	*swap;

	length = ft_strlen(*str);
	if (precision > length)
	{
		swap = ft_strpad(*str, precision - length, '0', false);
		free(*str);
		*str = swap;
	}
}

void			format_precision_str(size_t precision, char **str)
{
	size_t	length;
	char	*swap;

	length = ft_strlen(*str);
	if (precision < length)
	{
		swap = ft_strndup(*str, precision);
		free(*str);
		*str = swap;
	}
}

_Bool			is_zero_fill(t_conv *conv)
{
	return ((!(conv->flags & MINUS_FLAG)) \
				&& (conv->flags & ZERO_FLAG) \
				&& (!(conv->flags & HAS_PRECISION)));
}

void			format_min_width(t_conv *conv, char **str)
{
	size_t	length;
	char	*swap;

	length = ft_strlen(*str);
	if (conv->min_width > length)
	{
		swap = ft_strpad(*str, conv->min_width - length, \
				is_zero_fill(conv) ? '0' : ' ', (conv->flags & MINUS_FLAG));
		free(*str);
		*str = swap;
	}
}
