/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:35:16 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:27:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci.h"

static int	check_first_line(t_env *env)
{
	int		ret;
	char	buf;

	while ((ret = read(env->fd, &buf, 1)) > 0)
	{
		if (buf == 'X' || buf == '.')
			env->numcols++;
		else if (buf == '\n')
		{
			env->numlines = 1;
			break ;
		}
		else
			return (1);
	}
	if (ret < 0 || env->numcols < 1 || env->numlines != 1 || env->numcols > 1024)
		return (1);
	return (0);
}

static int	check_next_lines(t_env *env)
{
	int     ret;
    char    buf;
	int		curncol = 0;

    while ((ret = read(env->fd, &buf, 1)) > 0)
	{
		if (buf == 'X' || buf == '.')
			curncol++;
		else if (buf == '\n')
		{
			if (curncol != env->numcols)
				return (1);
			env->numlines++;
			curncol = 0;
		}
		else
			return (1);
	}
	if (ret < 0 || curncol != 0)
		return (1);
	return (0);
}

static int	savemap(t_env *env)
{
	int     ret;
    char    buf;
	char	**lineptr = env->lines;
	char	*colptr;
	int		newline = 1;

    while ((ret = read(env->fd, &buf, 1)) > 0)
	{
		if (newline)
		{
			*lineptr = malloc(sizeof(char) * (env->numcols + 1));
			if (*lineptr == NULL)
				return (1);
			ft_bzero(*lineptr, sizeof(char) * (env->numcols + 1));
			colptr = *lineptr;
			lineptr++;
			newline = 0;
		}
		if (buf == '\n')
			newline = 1;
		else
			*colptr++ = buf;
	}
	if (ret < 0)
        return (1);
	return (0);
}

int         savefile(t_env *env, char *filename)
{
	env->fd = open(filename, O_RDONLY);
	if (env->fd < 0)
		return (1);
	if (check_first_line(env) != 0)
		return (1);
	if (check_next_lines(env) != 0)
		return (1);
	close(env->fd);
	env->fd = open(filename, O_RDONLY);
    if (env->fd < 0)
        return (1);
	env->lines = malloc(sizeof(char*) * (env->numlines + 1));
	if (env->lines == NULL)
		return (1);
	ft_bzero(env->lines, sizeof(char*) * (env->numlines + 1));
	if (savemap(env))
		return (1);
	close(env->fd);
	return (0);
}
