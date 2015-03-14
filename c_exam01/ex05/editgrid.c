/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 11:26:40 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:27:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count.h"

void		follow_island(char **grid, int line, int col, char nbr)
{
	grid[line][col] = nbr;
	if (line != 0 && grid[line - 1][col] == 'X')
		follow_island(grid, line - 1, col, nbr);
	if (col != 0 && grid[line][col - 1] == 'X')
		follow_island(grid, line, col - 1, nbr);
	if (grid[line][col + 1] == 'X')
		follow_island(grid, line, col + 1, nbr);
	if (grid[line + 1][col] == 'X')
		follow_island(grid, line + 1, col, nbr);
}

int			edit_grid(char **grid, int data[2])
{
	int		tmpdat[2];
	int		island_number;

	tmpdat[1] = 0;
	island_number = '0';
	while (tmpdat[1] < data[1])
	{
		tmpdat[0] = 0;
		while (tmpdat[0] < data[0])
		{
			if (grid[tmpdat[1]][tmpdat[0]] == 'X')
				follow_island(grid, tmpdat[1], tmpdat[0],
							(char)island_number++);
			tmpdat[0]++;
		}
		tmpdat[1]++;
	}
	if (island_number > 10 + '0')
		return (1);
	return (0);
}
