/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:50:31 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:47:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				strnequ_fullyequ(char *ref, char *str, size_t n)
{
	while (n--)
	{
		if (*ref == '\0')
			return (0);
		if (*str == '\0')
			return (0);
		if (*ref++ != *str++)
			return (0);
	}
	return (1);
}

static int		is_in_str(char *ref, size_t reflen, char *str)
{
	while (*str != '\0')
	{
		if (strnequ_fullyequ(ref, str, reflen))
			return (1);
		str++;
	}
	return (0);
}

static int		ina(char *ref, size_t reflen, int ac, char **av)
{
	while (--ac >= 2)
		if (!is_in_str(ref, reflen, av[ac]))
			return (0);
	return (1);
}

static void		print_error(int ac, char **av)
{
	if (ac == 2)
		while (*av[1] != '\0')
			write(1, av[1]++, 1);
}

int				main(int ac, char **av)
{
	int		i[4];

	print_error(ac, av);
	if (ac >= 3)
	{
		i[0] = 0;
		i[1] = 0;
		i[2] = 0;
		while (av[1][i[0]] != '\0')
		{
			i[3] = 0;
			while (av[1] + i[3] != '\0' && ina(av[1] + i[0], i[3] + 1, ac, av))
				i[3]++;
			if (i[3] > i[1])
			{
				i[1] = i[3];
				i[2] = i[0];
			}
			i[0]++;
		}
		write(1, av[1] + i[2], i[1]);
	}
	write(1, "\n", 1);
	return (0);
}
