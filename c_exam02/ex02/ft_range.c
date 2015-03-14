/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 09:24:37 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 09:31:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int	*ret;
	int	i;

	ret = (int*)malloc(sizeof(int) *
				((end > start) ? (end - start + 1) : (start - end + 1)));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		ret[i++] = start;
		if (start == end)
			break ;
		start += (end > start) ? 1 : -1;
	}
	return (ret);
}
