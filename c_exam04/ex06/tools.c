/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:19:13 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 12:23:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oa.h"

void		ft_bzero(void *ptr, size_t size)
{
	while (size--)
		*(char*)ptr++ = '\0';
	return ;
}

size_t		ft_strlen(char *str)
{
	size_t	tot = 0;

	while (*str++) 
		tot++;
	return (tot);
}

int			ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

size_t		ft_wordlen(char *str)
{
	size_t	tot = 0;

	while (*str && !ft_isspace(*str))
	{ 
		tot++;
		str++;
	}
	return (tot);
}

char		ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}


int			is_strref_best(char *str_ref, char *str_guest)
{
	if (str_ref == NULL)
		return (0);
	if (ft_wordlen(str_ref) < ft_wordlen(str_guest))
		return (1);
	else if (ft_wordlen(str_ref) > ft_wordlen(str_guest))
		return (0);
	while (*str_ref != '\0' && !ft_isspace(*str_ref) &&
		   ft_tolower(*str_ref) == ft_tolower(*str_guest))
	{
		str_ref++;
		str_guest++;
	}
	if (*str_ref == '\0' || ft_isspace(*str_ref))
	{
		if (str_ref < str_guest)
			return (1);
		return (0);
	}
	if (ft_tolower(*str_ref) <= ft_tolower(*str_guest))
		return (1);
	return (0);
}

void		erase_word(char *wordstart)
{
	while (*wordstart != '\0' && !ft_isspace(*wordstart))
		*wordstart++ = ' ';
	return ;
}
