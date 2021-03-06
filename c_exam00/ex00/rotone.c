/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:36:30 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 09:36:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int		main(int ac, char *av[])
{
	int	i;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
			av[1][i] = (av[1][i] - 'a' + 1) % 26 + 'a';
		if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			av[1][i] = (av[1][i] - 'A' + 1) % 26 + 'A';
		i++;
	}
	ft_putstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
