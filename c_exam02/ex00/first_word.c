/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 09:13:51 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 09:16:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int		t;

	if (ac == 2)
	{
		t = 0;
		while (*av[1] != '\0')
		{
			if (*av[1] == ' ' || *av[1] == '\t')
			{
				if (t == 1)
					break ;
			}
			else
			{
				t = 1;
				write(1, av[1], 1);
			}
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
