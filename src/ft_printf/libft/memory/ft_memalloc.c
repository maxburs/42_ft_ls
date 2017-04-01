/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:19:29 by mburson           #+#    #+#             */
/*   Updated: 2016/12/01 17:19:31 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char*)new)[i] = 0;
		i++;
	}
	return (new);
}
