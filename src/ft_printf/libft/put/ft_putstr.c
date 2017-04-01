/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:30:21 by mburson           #+#    #+#             */
/*   Updated: 2016/12/03 15:30:23 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(const char *s)
{
	if (!s)
		ft_putstr("(null)");
	else
		write(1, s, sizeof(char) * ft_strlen(s));
}
