/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:10:46 by mburson           #+#    #+#             */
/*   Updated: 2016/12/21 19:10:48 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HASH_FLAG 0x01
# define ZERO_FLAG 0x02
# define MINUS_FLAG 0x04
# define PLUS_FLAG 0x08
# define SPACE_FLAG 0x10
# define IS_NEG 0x20
# define HAS_PRECISION 0x40
# define VAR_WIDTH_FLAG 0x80
# define VAR_PRECISION_FLAG 0x100

# define HH_LENGTH 1
# define H_LENGTH 2
# define L_LENGTH 3
# define LL_LENGTH 4
# define J_LENGTH 5
# define Z_LENGTH 6

# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include <wchar.h>

typedef	struct	s_conv
{
	char			letter;
	unsigned int	flags;
	unsigned int	length;
	unsigned int	min_width;
	unsigned int	precision;
}				t_conv;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
/*
** does not work in molunette branch
** int				ft_asprintf(char **ret, const char *format, ...);
*/

/*
** inference.c
*/
void			inference(t_conv *conv);

/*
** conv.c
*/
void			build_conv(const char **format, t_conv *conv);
void			zero_conv(t_conv *conv);

/*
** ./parse/
*/
char			*parse(t_conv *conv, va_list *ap);
char			*parse_char(t_conv *conv, va_list *ap);
char			*parse_char_wide(va_list *ap);
char			*parse_int(t_conv *conv, va_list *ap);
char			*num_to_string(t_conv *conv, uintmax_t num);
char			*parse_ptr(va_list *ap);
char			*parse_str(t_conv *conv, va_list *ap);
char			*parse_str_wide(t_conv *conv, va_list *ap);

/*
** format.c
*/
char			*format_str(t_conv *conv, char *str);
void			format_precision(size_t precision, char **str);

/*
** format_cont.c
** functions that wouldn't fit in format.c
*/
char			*ft_strpad(char *str, size_t n, char c, _Bool back);
void			format_precision(size_t precision, char **str);
void			format_precision_str(size_t precision, char **str);
_Bool			is_zero_fill(t_conv *conv);
void			format_min_width(t_conv *conv, char **str);

/*
** debug.c
*/
void			print_conv(t_conv *conv);

#endif
