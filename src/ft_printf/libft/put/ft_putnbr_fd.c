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

static void		recurs(int n, int fd)
{
	if (!n)
		return ;
	recurs(n / 10, fd);
	ft_putchar_fd((char)(n % 10 + 48), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (!n)
		return (ft_putchar_fd('0', fd));
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	recurs(n, fd);
}
