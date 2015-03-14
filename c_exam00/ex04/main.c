/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:57:28 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 12:45:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "diam.h"

int			find_maxlnknb(char *str)
{
	int		max;
	int		tmp;

	max = 0;
	while (*str != '\0')
	{
		tmp = get_number(&str);
		if (tmp > max)
			max = tmp;
		if (*str != '\0')
			str++;
	}
	return (max);
}

t_pair		*alloc_mem(int size)
{
	t_pair	*ptr;

	ptr = (t_pair*)malloc(sizeof(t_pair) * (size + 1));
	if (!ptr)
		return (NULL);
	ft_bzero((void*)ptr, sizeof(t_pair) * (size + 1));
	return (ptr);
}

static void	populate(t_pair *pairs, char *str)
{
	int		tmp;

	while (*str != '\0')
	{
		tmp = get_number(&str);
		if (*str == '-')
			pairs->a = tmp;
		if (*str == ' ' || *str == '\0')
		{
			pairs->b = tmp;
			pairs++;
		}
		if (*str != '\0')
			str++;
	}	
}

void		ft_putnbr(int i)
{
	if (i >= 10)
		ft_putnbr(i / 10);
	i = i % 10 + '0';
	write(1, &i, 1);
}

int			main(int ac, char *av[])
{
	int		maxlinknb;
	t_pair	*pairs;
	int		nb;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	maxlinknb = find_maxlnknb(av[1]);
	if (!(pairs = alloc_mem(maxlinknb)))
		return (0);
	populate(pairs, av[1]);
	if ((nb = find_max_jumps(pairs, maxlinknb)) < 0)
		return (0);
	ft_putnbr(nb);
	write(1, "\n", 1);
	return (0);
}
