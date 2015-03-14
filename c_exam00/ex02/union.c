/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:40:02 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 09:54:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_stared(char stared[256])
{
	while (*stared != '\0')
		write(1, stared++, 1);
}

static void	add_in_stared(char stared[256], char c)
{
	while (*stared != '\0')
		stared++;
	*stared = c;
}

static int	is_in_str(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static void	populate_stared(char stared[256], char *s)
{
	while (*s != '\0')
	{
		if (!is_in_str(stared, *s))
			add_in_stared(stared, *s);
		s++;
	}
}

int			main(int ac, char *av[])
{
	char	stared[256];
	int		i;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < 256)
	{
		stared[i] = '\0';
		i++;
	}
	populate_stared(stared, av[1]);
	populate_stared(stared, av[2]);
	print_stared(stared);
	write(1, "\n", 1);
	return (0);
}
