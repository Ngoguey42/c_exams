/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 11:07:35 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:30:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count.h"

int			fill_grid(char **grid, char *str, int fd)
{
	int		i;
	char	buf[BUFFSIZE + 1];
	int		tmpdat[2];
	int		ret;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (1);
	ft_bzero(tmpdat, 2 * sizeof(int));
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		i = -1;
		while (++i < (int)ret)
		{
			if (buf[i] != '\n')
				grid[tmpdat[1]][tmpdat[0]] = buf[i];
			tmpdat[0]++;
			if (buf[i] == '\n')
			{
				tmpdat[0] = 0;
				tmpdat[1]++;
			}
		}
	}
	close(fd);
	return (0);
}
