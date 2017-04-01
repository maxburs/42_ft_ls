/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:48:36 by mburson           #+#    #+#             */
/*   Updated: 2017/01/09 21:48:38 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>

void					print_conv(t_conv *conv)
{
	printf("---\n");
	printf("       letter: %c\n", conv->letter);
	printf("        flags: %X\n", conv->flags);
	printf("       length: %d\n", conv->length);
	printf("    min_width: %zu\n", conv->min_width);
	printf("    precision: %zu\n", conv->precision);
	printf("---\n");
}
