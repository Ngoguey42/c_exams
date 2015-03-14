/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:34:38 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 12:03:50 by exam             ###   ########.fr       */
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

static void	print_word(char *wstart)
{
	while (*wstart && *wstart != ' ' && *wstart != '\t')
		write(1, wstart++, 1);
	return ;
}

static void	print_rev(char *orig, char *head)
{
	int	t;

	t = 0;
	while (head > orig)
	{
		if (*head == ' ' || *head == '\t')
		{
			if (t)
				write(1, " ", 1);
			else
				t = 1;
			print_word(head + 1);
		}
		head--;
	}
	if (t)
		write(1, " ", 1);
	else
		t = 1;
	print_word(orig);
	return ;
}

int		main(int ac, char *av[])
{
	if (ac == 2)
	{
		print_rev(av[1], av[1] + ft_strlen(av[1]) - 1);
	}
	write(1, "\n", 1);
	return (0);
}
