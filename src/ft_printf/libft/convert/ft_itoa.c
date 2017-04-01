/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:25:54 by mburson           #+#    #+#             */
/*   Updated: 2016/12/03 13:25:56 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_itoa(int n)
{
	char	*word;
	int		i;
	_Bool	neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numlen((long)n, 10);
	if (!(word = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	word[i] = '\0';
	neg = 0;
	if (n < 0)
	{
		n *= -1;
		word[0] = '-';
		neg = 1;
	}
	i--;
	while (i >= (int)neg)
	{
		word[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (word);
}
