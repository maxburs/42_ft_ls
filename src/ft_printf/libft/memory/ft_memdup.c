/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:50:23 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 19:50:25 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	*ft_memdup(const void *mem, size_t size)
{
	void		*new;
	size_t		i;

	if (!(new = (void*)malloc(size)))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		((unsigned char *)new)[i] = ((unsigned char *)mem)[i];
		i++;
	}
	return (new);
}
