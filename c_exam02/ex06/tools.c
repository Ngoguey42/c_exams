/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 10:42:07 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 11:11:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mul.h"

void	ft_bzero(void *ptr, size_t s)
{
	while (s--)
		*((char*)ptr++) = 0;
}

void	ft_memset(void *ptr, unsigned char c, size_t s)
{
	while (s--)
		*((char*)ptr++) = c;
}

size_t	ft_strlen(char *ptr)
{
	size_t	ret;

	ret = 0;
	while (*ptr++)
		ret++;
	return (ret);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
