/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:19:13 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 09:20:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci.h"

void		ft_bzero(void *ptr, size_t size)
{
	while (size--)
		*(char*)ptr++ = '\0';
	return ;
}

size_t		ft_strlen(char *str)
{
	size_t	tot = 0;

	while (*str++) 
		tot++;
	return (tot);
}
