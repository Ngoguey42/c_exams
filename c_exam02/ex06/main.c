/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 10:34:11 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 12:49:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mul.h"

char	*get_estr(int datas[10])
{
	char	*ret;

	ret = malloc(datas[0] + 2);
	ft_bzero(ret, datas[0] + 2);
	ft_memset(ret, '0', datas[0]);
	return (ret);
}

void	input_nbr(char *nb, char *dst, size_t dstlen)
{
	size_t		i;
	size_t		j;

	i = dstlen - 1;
	j = ft_strlen(nb);
	while (j--)
	{
		if (nb[j] == '-')
			return ;
		dst[i] = nb[j];
		i--;
	}
}

void	input_nbr_pad(char *nb, char *dst, size_t dstlen, int pad)
{
	size_t		i;
	size_t		j;

	i = dstlen - 1 - pad;
	j = ft_strlen(nb);
	while (j--)
	{
		if (nb[j] == '-')
			return ;
		dst[i] = nb[j];
		i--;
	}
}

void	alloc_orig(char *n1, char *n2, char *orig[2], int datas[10])
{
	size_t	sz;

	sz = MAX(ft_strlen(n1), ft_strlen(n2));
	datas[0] = sz * 2;
	orig[0] = get_estr(datas);
	orig[1] = get_estr(datas);
	input_nbr(n1, orig[0], datas[0]);
	input_nbr(n2, orig[1], datas[0]);
}

int		main(int ac, char *av[])
{
	char	*orig[2];
	int		datas[10];
	char	*res;

	ft_bzero(datas, sizeof(datas));
	alloc_orig(av[1], av[2], orig, datas);
	res = get_estr(datas);
	domult(orig, datas, res);
	while (*res == '0')
		res++;
	if (*res == '\0')
		ft_putstr("0");
	else if (*av[1] == '-' && *av[2] == '-')
		(void)ac;
	else if (*av[1] == '-' || *av[2] == '-')
		write(1, "-", 1);
	ft_putstr(res);
	write(1, "\n", 1);
	return (0);
}
