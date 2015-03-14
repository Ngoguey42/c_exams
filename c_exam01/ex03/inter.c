/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:42:41 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:43:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(const char *s)
{
	while (*s != '\0')
		ft_putchar(*s++);
}

static int		is_in_str(char c, char *str)
{
	while (*str != '\0')
		if (*str++ == c)
			return (1);
	return (0);
}

void			ft_bzero(void *dat, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)dat;
	while (len--)
	{
		*ptr++ = 0;
	}
}

int				main(int ac, char **av)
{
	int		i;
	char	buf[257];

	if (ac != (1 + 2))
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	ft_bzero(buf, sizeof(char) * 257);
	while (*av[1] != '\0')
	{
		if (!is_in_str(*av[1], buf) && is_in_str(*av[1], av[2]))
			buf[i++] = *av[1];
		av[1]++;
	}
	ft_putstr(buf);
	ft_putchar('\n');
	return (0);
}
