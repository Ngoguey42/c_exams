/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependancies2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 11:27:13 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 12:04:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diam.h"

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		get_number(char **pos)
{
	int	total;

	total = 0;
	while (**pos != '\0' && ft_isdigit(**pos))
	{
		total = total * 10 + **pos - '0';
		(*pos)++;
	}
	return (total);
}

void	ft_bzero(void *tab, size_t n)
{
	unsigned char	*ptr;
	
	ptr = (unsigned char*)tab;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

void	ft_bmone(void *tab, size_t n)
{
	unsigned char	*ptr;
	
	ptr = (unsigned char*)tab;
	while (n--)
	{
		*ptr = -1;
		ptr++;
	}
}
