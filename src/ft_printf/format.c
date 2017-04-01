/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:29:26 by mburson           #+#    #+#             */
/*   Updated: 2017/01/09 21:29:27 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <string.h>
#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

static char		find_sign(t_conv *conv)
{
	if (conv->flags & IS_NEG)
	{
		return ('-');
	}
	else if (conv->flags & PLUS_FLAG)
	{
		return ('+');
	}
	else if (conv->flags & SPACE_FLAG)
	{
		return (' ');
	}
	else
	{
		return ('\0');
	}
}

static void		add_sign(t_conv *conv, char **str, _Bool inside_ok)
{
	char	*swap;
	char	sign;

	if (!(sign = find_sign(conv)))
		return ;
	if (inside_ok && (*str)[0] == '0')
	{
		(*str)[0] = sign;
	}
	else
	{
		if (!(swap = (char*)malloc(sizeof(char) * (ft_strlen(*str) + 2))))
		{
			ft_strdel(str);
			return ;
		}
		ft_strcpy(swap + 1, *str);
		swap[0] = sign;
		free(*str);
		*str = swap;
	}
}

static void		handle_hash_o(t_conv *conv, char *str)
{
	size_t	length;

	if ((conv->letter != 'o') || !(conv->flags & HASH_FLAG))
		return ;
	length = ft_strlen(str);
	if (conv->precision <= length)
		conv->precision = length + 1;
}

static void		precision_hash_x(t_conv *conv, char **str)
{
	char	*swap;

	if (!**str || ((*str)[0] == '0' && (*str)[1] == '\0'))
	{
		format_min_width(conv, str);
	}
	else if ((conv->min_width > ft_strlen(*str) + 2) \
				&& (conv->flags & ZERO_FLAG) && !(conv->flags & IS_NEG) \
				&& !(conv->flags & HAS_PRECISION))
	{
		format_min_width(conv, str);
		(*str)[1] = conv->letter;
	}
	else
	{
		swap = ft_strjoin(conv->letter == 'X' ? "0X" : "0x", *str);
		free(*str);
		*str = swap;
		format_min_width(conv, str);
	}
}

char			*format_str(t_conv *conv, char *str)
{
	handle_hash_o(conv, str);
	if (conv->letter != 's' && conv->letter != 'c')
		format_precision(conv->precision, &str);
	else if (conv->flags & HAS_PRECISION)
		format_precision_str(conv->precision, &str);
	if ((conv->letter == 'x' || conv->letter == 'X') \
			&& (conv->flags & HASH_FLAG))
		precision_hash_x(conv, &str);
	else if (conv->min_width > ft_strlen(str) && is_zero_fill(conv))
	{
		format_min_width(conv, &str);
		add_sign(conv, &str, true);
	}
	else
	{
		add_sign(conv, &str, false);
		format_min_width(conv, &str);
	}
	return (str);
}
