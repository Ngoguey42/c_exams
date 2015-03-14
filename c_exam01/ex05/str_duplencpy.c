/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:35:09 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 11:41:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_bzero(void *dat, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)dat;
	while (len--)
		*ptr++ = 0;
}

size_t		ft_strlen(char *s)
{
	size_t	to;

	to = 0;
	while (*s != '\0')
	{
		s++;
		to++;
	}
	return (to);
}

char		*ft_strcpy(char *dst, char *src)
{
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

char		*ft_strdup(char *src)
{
	char	*ret;

	if (src == NULL)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (NULL);
	ft_strcpy(ret, src);
	return (ret);
}
