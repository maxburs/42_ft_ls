/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:23:39 by mburson           #+#    #+#             */
/*   Updated: 2016/12/02 19:23:41 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** copies the src string to the dst
** returns the last character in the dst that was copied
*/

char	*ft_strplace(char *dst, const char *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		(dst)[i] = (src)[i];
		i++;
	}
	return (&(dst[i - 1]));
}
