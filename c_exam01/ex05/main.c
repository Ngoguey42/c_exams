/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:21:28 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:31:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count.h"

int			main(int ac, char **av)
{
	int		data[2];
	char	**grid;
	int		ret;

	grid = NULL;
	data[0] = -1;
	data[1] = 0;
	ret = is_grid_valid(data, &grid, ac, av);
	if (ac > 1 && ret > 0)
	{
		if (fill_grid(grid, av[1], 0) == 0)
			if (edit_grid(grid, data) == 0)
				print_grid(grid, data);
	}
	ft_putchar('\n');
	return (0);
}
