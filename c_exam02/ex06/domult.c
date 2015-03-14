/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domult.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 11:12:31 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 12:52:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mul.h"

void	doadd(char *home, char *guest, int nnbr)
{
	char	carry;

	carry = 0;
	while (--nnbr > 0)
	{
		if (home[nnbr] - '0' + guest[nnbr] - '0' + carry <= 9)
		{
			home[nnbr] += guest[nnbr] - '0' + carry;
			carry = 0;
		}
		else
		{
			home[nnbr] += guest[nnbr] - '0' + carry - 10;
			carry = 1;
		}
	}
	return ;
}

void	apply_cur_s1_nbr(char *tmpnbr, int datas[10], char *res, int times)
{
	while (times-- > 0)
	{
		doadd(res, tmpnbr, datas[0]);
	}
	return ;
}

void	domult(char *orig[2], int datas[10], char *res)
{
	char	*tmpnbr;
	int		i;

	i = -1;
	while (++i < datas[0])
	{
		if (orig[1][datas[0] - 1 - i] - '0' == 0)
			continue ;
		tmpnbr = get_estr(datas);
		input_nbr_pad(orig[0], tmpnbr, datas[0], i);
		apply_cur_s1_nbr(tmpnbr, datas, res, orig[1][datas[0] - 1 - i] - '0');
	}
	return ;
}
