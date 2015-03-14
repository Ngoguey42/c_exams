/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependancies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 10:01:21 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 10:58:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "alphlong.h"

int				ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

char			ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

static void		ft_bzero(void *tab, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)tab;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

static char		**alloc_tab(char *str)
{
	int		t;
	int		total;
	char	**table;

	total = 0;
	t = 0;
	while (*str != '\0')
	{
		if (ft_isspace(*str))
			t = 0;
		else
		{
			if (t == 0)
				total++;
			t = 1;
		}
		str++;
	}
	if (!(table = (char**)malloc(sizeof(char*) * (total + 1))))
		return (NULL);
	ft_bzero((void*)table, sizeof(char*) * (total + 1));
	return (table);
}

int				ft_strsplit(char ***words, char *str)
{
	int		t;
	char	**tab;

	if (!(tab = alloc_tab(str)))
		return (1);
	*words = tab;
	t = 0;
	while (*str != '\0')
	{
		if (ft_isspace(*str))
			t = 0;
		else
		{
			if (t == 0)
				*tab++ = str;
			t = 1;
		}
		str++;
	}
	return (0);
}
