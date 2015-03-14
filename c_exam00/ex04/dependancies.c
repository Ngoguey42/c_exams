/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependancies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 11:24:11 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 12:57:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diam.h"

#define MAX(A, B) (A > B ? A : B)

int	jump_from_here(t_pair *pairs, int starti, int startnb, int *trace)
{
	int	i;
	int	r;

	insert_trace(trace, pairs[starti].a);
	insert_trace(trace, pairs[starti].b);
	pairs[starti].visited = 1;
	i = 0;
	r = 0;
	while (pairs[i].b != 0 && pairs[i].a != 0)
	{
		if (pairs[i].visited == 0 && pairs[i].a == startnb)
		{
			if (!is_in_trace(trace, pairs[i].b))
				r = MAX(r, jump_from_here(pairs, i, pairs[i].b, trace));
			else
				r = MAX(r, 1);
		}
		if (pairs[i].visited == 0 && pairs[i].b == startnb)
		{
			if (!is_in_trace(trace, pairs[i].a))
				r = MAX(r, jump_from_here(pairs, i, pairs[i].a, trace));
			else
				r = MAX(r, 1);
		}
		i++;
	}
	rm_in_trace(trace, pairs[starti].a);
	rm_in_trace(trace, pairs[starti].b);
	pairs[starti].visited = 0;
	return (r + 1);
}

int	find_max_jumps(t_pair *pairs, int maxlnknb)
{
	int	max;
	int	i;
	int	tmp;
	int	*trace;

	if (!(trace = (int*)malloc(sizeof(int) * (maxlnknb + 1))))
		return (-1);
	i = 0;
	tmp = 0;
	max = 0;
	while (pairs[i].b != 0 && pairs[i].a != 0)
	{
		ft_bmone((void*)trace, sizeof(int) * (maxlnknb + 1));
		tmp = jump_from_here(pairs, i, pairs[i].a, trace);
		if (tmp > max)
			max = tmp;
		ft_bmone((void*)trace, sizeof(int) * (maxlnknb + 1));
		tmp = jump_from_here(pairs, i, pairs[i].b, trace);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}
