/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:42:31 by mburson           #+#    #+#             */
/*   Updated: 2016/12/03 13:42:33 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** finds the length needed to represent and undefined number
**		in the given base
*/

int		ft_numlen_un(uintmax_t n, uintmax_t base)
{
	int		size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= base;
	}
	return (size);
}
