/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:26:58 by mburson           #+#    #+#             */
/*   Updated: 2016/12/01 13:26:59 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static _Bool	is_lower(int c)
{
	return (96 < c && c < 123);
}

static _Bool	is_upper(int c)
{
	return (64 < c && c < 91);
}

int				ft_isalpha(int c)
{
	return (is_upper(c) || is_lower(c));
}
