/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:12:28 by mburson           #+#    #+#             */
/*   Updated: 2016/12/03 17:12:29 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	size_t len;

	len = ft_strlen(s);
	write(fd, (const void *)s, len);
	ft_putchar_fd('\n', fd);
}
