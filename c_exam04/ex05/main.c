/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:14:30 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:18:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci.h"

void	printmap(char **lines)
{
	char	*col;

	while (*lines != NULL)
	{
		col = *lines;
		while (*col != '\0')
			write(1, col++, 1);
		write(1, "\n", 1);
		lines++;
	}
	return ;
}

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	recurse_from_char(t_env *e, int iline, int icol, char c)
{
	e->lines[iline][icol] = c;
	if (iline > 0 && e->lines[iline - 1][icol] == 'X')
		recurse_from_char(e, iline - 1, icol, c);
	if (iline < e->numlines - 1 && e->lines[iline + 1][icol] == 'X')
		recurse_from_char(e, iline + 1, icol, c);
	if (icol > 0 && e->lines[iline][icol - 1] == 'X')
		recurse_from_char(e, iline, icol - 1, c);
	if (icol < e->numcols - 1 && e->lines[iline][icol + 1] == 'X')
		recurse_from_char(e, iline, icol + 1, c);
	return ;
}

static int	solvemap(t_env *e)
{
	char	curchar = '0';
	int		iline = 0;
	int		icol;
	char	cur;

	while (e->lines[iline] != NULL)
	{
		icol = 0;
		while ((cur = e->lines[iline][icol]) != '\0')
		{
			if (cur == 'X')
			{
				if (curchar > '9')
					return (1);
				recurse_from_char(e, iline, icol, curchar++);
			}
			icol++;
		}
		iline++;
	}

	return (0);
}


int		main(int ac, char *av[])
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (ac >= 2)
	{
		if (savefile(&env, av[1]) == 0)
		{
			if (solvemap(&env) == 0)
			{
				printmap(env.lines);
				return (0);
			}
		}

	}
	write(1, "\n", 1);
	return (0);
}
