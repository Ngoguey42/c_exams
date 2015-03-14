/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependancies2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 10:29:39 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 11:17:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alphlong.h"

int			word_len(char *str)
{
	int total;

	total = 0;
	while (*str != '\0' && !ft_isspace(*str++))
		total++;
	return (total);
}

void		move_index(char **words, int i1, int i2)
{
	char	*tmpi2;
	int		i;

	tmpi2 = words[i2];
	i = i2 - 1;
	while (i >= i1)
	{
		words[i + 1] = words[i];
		i--;
	}
	words[i1] = tmpi2;
}

int			is_word2_better(char *w1, char *w2)
{
	int	s1;
	int	s2;

	s1 = word_len(w1);
	s2 = word_len(w2);
	if (s2 > s1)
		return (0);
	if (s1 > s2)
		return (1);
	while (ft_tolower(*w1) == ft_tolower(*w2))
	{
		if (*w1 == '\0')
			return (0);
		w1++;
		w2++;
	}
	if (ft_tolower(*w2) < ft_tolower(*w1))
		return (1);
	return (0);
}

int			get_better_index(char **words, int i1)
{
	int		i;
	int		bti;
	int		prevbti;

	i = i1 + 1;
	bti = -1;
	prevbti = -1;
	while (words[i] != NULL)
	{
		if (is_word2_better(words[i1], words[i]))
		{
			bti = i;
			if (prevbti == -1)
				prevbti = bti;
			else if (is_word2_better(words[prevbti], words[bti]))
				prevbti = bti;
		}
		i++;
	}
	return (prevbti);
}
