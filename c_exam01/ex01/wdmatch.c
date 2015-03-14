/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:28:54 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:33:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(const char *s)
{
	while (*s != '\0')
		ft_putchar(*s++);
}

static int		is_wdmatching(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s2 == '\0')
			return (0);
		else
			s2++;
	}
	if (*s1 == '\0')
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	if (ac != (1 + 2))
	{
		ft_putchar('\n');
		return (0);
	}
	if (is_wdmatching(av[1], av[2]))
		ft_putstr(av[1]);
	ft_putchar('\n');
	return (0);
}
