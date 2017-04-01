/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:59:01 by mburson           #+#    #+#             */
/*   Updated: 2016/10/31 16:59:03 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** converts a string to an int
*/

int	ft_atoi(const char *str)
{
	long		result;
	size_t		index;
	_Bool		negative;

	result = 0;
	index = 0;
	negative = 0;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-')
	{
		index++;
		negative = 1;
	}
	else if (str[index] == '+')
		index++;
	while (47 < str[index] && str[index] < 58)
	{
		result = 10 * result + str[index] - 48;
		index++;
	}
	if (negative)
		result *= -1;
	return (result);
}
