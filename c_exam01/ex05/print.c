/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 11:21:59 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 11:26:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count.h"

void		print_grid(char **grid, int data[2])
{
	while (--data[1] >= 0)
	{
		ft_putstr(*grid);
		if (data[1] > 0)
			ft_putchar('\n');
		grid++;
	}
}
