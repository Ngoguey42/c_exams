/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:14:30 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 12:24:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oa.h"

static size_t	num_words(char *av)
{
	size_t	tot = 0;
	int		t = 0;

	while (*av)
	{
		if (ft_isspace(*av))
			t = 0;
		else if (t == 0)
		{
			tot++;
			t = 1;
		}
		av++;
	}
	return (tot);
}

static void	print_word(char *str)
{
	while (*str && !ft_isspace(*str))
		write(1, str++, 1);
	return ;
}

static char	*find_best(char *str)
{
	char	*curbest = NULL;

	while (*str != '\0')
	{
		if (ft_isspace(*str))
			str++;
		else
		{
			if (!is_strref_best(curbest, str))
				curbest = str;
			while (!ft_isspace(*str) && *str != '\0')
				str++;
		}
	}
	return (curbest);
}

static void	solve(char *str)
{
	char	*best;
	size_t	prevlen = 0;
	int		t = 0;

	while (num_words(str) > 0)
	{
		best = find_best(str);
		if (prevlen > 0 && ft_wordlen(best) != prevlen)
		{
			write(1, "\n", 1);
			t = 0;
		}
		if (t)
			write(1, " ", 1);
		t = 1;
		prevlen = ft_wordlen(best);
		print_word(best);
		erase_word(best);
	}
	return ;
}

int		main(int ac, char *av[])
{
	if (ac == 2)
	{
		if (num_words(av[1]) > 0)
		{
			solve(av[1]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
