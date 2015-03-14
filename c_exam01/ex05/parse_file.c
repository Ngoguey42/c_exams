/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:25:15 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:31:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count.h"

static int		is_update_tmpdat(int dat[2], int tmpdat[2])
{
	if (dat[0] < 0)
		dat[0] = tmpdat[0];
	else if (dat[0] != tmpdat[0])
		return (1);
	if (dat[0] <= 0 || dat[0] > 1024)
		return (1);
	dat[1]++;
	tmpdat[0] = 0;
	tmpdat[1] = 0;
	return (0);
}

static int		fill_dat(int data[2], int fd)
{
	int		i;
	char	buf[BUFFSIZE + 1];
	int		tmpdat[2];
	int		ret;

	tmpdat[0] = 0;
	tmpdat[0] = 0;
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		i = -1;
		while (++i < (int)ret)
		{
			if (buf[i] != '\n' && buf[i] != '.' && buf[i] != 'X')
				return (1);
			if (buf[i] != '\n')
				tmpdat[0]++;
			else if (is_update_tmpdat(data, tmpdat))
				return (1);
		}
	}
	if (ret < 0)
		return (1);
	if (buf[i - 1] != '\n')
		data[1]++;
	return (0);
}

int				is_grid_valid(int data[2], char ***grid, int ac, char **av)
{
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	if (fill_dat(data, fd))
		return (-2);
	if (data[1] <= 0 || data[0] <= 0)
		return (-3);
	close(fd);
	if ((*grid = (char**)malloc(sizeof(char*) * (data[1] + 1))) == NULL)
		return (-4);
	ft_bzero(*grid, sizeof(char*) * (data[1] + 1));
	fd = data[1] + 1;
	while (fd-- > 0)
	{
		(*grid)[fd] = (char*)malloc(sizeof(char) * (data[0] + 1));
		if ((*grid)[fd] == NULL)
			return (-5);
		ft_bzero((*grid)[fd], sizeof(char) * (data[0] + 1));
	}
	(void)ac;
	return (1);
}
