/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:27:38 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 09:32:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

static int	one_is_in_2(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			s2++;
	}
	if (*s1 == '\0')
		return (1);
	return (0);
}

int		main(int ac, char *av[])
{
	if (ac == 3)
	{
		if (one_is_in_2(av[1], av[2]))
			write(1, av[1], ft_strlen(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
