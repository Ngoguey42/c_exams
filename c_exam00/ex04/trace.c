/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 12:07:27 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 12:53:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diam.h"

void	insert_trace(int *trace, int i)
{
	while (*trace >= 0)
		trace++;
	*trace = i;
}

int		is_in_trace(int *trace, int i)
{
	while (*trace != i && *trace >= 0)
		trace++;
	if (*trace == i)
		return (1);
	return (0);
}

void	rm_in_trace(int *trace, int i)
{	
	while (*trace != i && *trace >= 0)
		trace++;
	if (*trace != i)
		return ;
	*trace = -1;
	while (trace[1] >= 0)
	{
		trace[0] = trace[1];
		trace++;
	}
	trace[0] = -1;
}
