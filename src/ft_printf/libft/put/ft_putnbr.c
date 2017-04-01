/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:40:02 by mburson           #+#    #+#             */
/*   Updated: 2016/12/03 15:40:03 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		recurs(int n)
{
	if (!n)
		return ;
	recurs(n / 10);
	ft_putchar((char)(n % 10 + 48));
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (!n)
		return (ft_putchar('0'));
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	recurs(n);
}
