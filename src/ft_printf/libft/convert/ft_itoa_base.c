/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:26:12 by mburson           #+#    #+#             */
/*   Updated: 2017/01/07 18:26:14 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>
#include <stdint.h>

/*
**	converts a number into a representation in the given base
*/

static char		rep_mask(int num, _Bool uppercase)
{
	if (0 <= num && num <= 9)
		return (num + '0');
	else if (uppercase)
		return (num - 10 + 'A');
	else
		return (num - 10 + 'a');
}

char			*ft_itoa_base(uintmax_t n, uintmax_t base, _Bool uppercase)
{
	char	*str;
	int		i;

	i = ft_numlen_un(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i)
	{
		i--;
		str[i] = rep_mask(n % base, uppercase);
		n /= base;
	}
	return (str);
}
