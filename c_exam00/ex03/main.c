/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:57:28 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 11:18:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "alphlong.h"

static void	ft_putword(char *str)
{
	while (*str != '\0' && !ft_isspace(*str))
		write(1, str++, 1);
}

static void	ft_putwords(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		if (i == 0)
			ft_putword(words[i]);
		else if (word_len(words[i]) == word_len(words[i - 1]))
		{
			write(1, " ", 1);
			ft_putword(words[i]);
		}
		else
		{
			write(1, "\n", 1);
			ft_putword(words[i]);
		}
		i++;
	}
}

static void	ft_sort_words(char **words)
{
	int		i;
	int		betteri;

	i = 0;
	while (words[i] != NULL)
	{
		betteri = get_better_index(words, i);
		if (betteri >= 0)
			move_index(words, i, betteri);
		i++;
	}
}

int			main(int ac, char *av[])
{
	char	**words;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_strsplit(&words, av[1]))
		return (1);
	ft_sort_words(words);
	ft_putwords(words);
	write(1, "\n", 1);
	free((void*)words);
	return (0);
}
