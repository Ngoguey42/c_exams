/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:15:22 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:27:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_H
# define CI_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_env
{
	int				fd;
	int				numlines;
	int				numcols;
	char			**lines;
	
}					t_env;

void        ft_bzero(void *ptr, size_t size);
size_t      ft_strlen(char *str);
int			savefile(t_env *env, char *filename);

#endif
