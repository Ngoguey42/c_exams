/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:21:04 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:37:45 by exam             ###   ########.fr       */
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

int				main(int ac, char **av)
{
	int		i;

	if (ac != (1 + 1))
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
			av[1][i] = av[1][i] - 'a' + 'A';
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			av[1][i] = av[1][i] - 'A' + 'a';
		i++;
	}
	ft_putstr(av[1]);
	ft_putchar('\n');
	return (0);
}
