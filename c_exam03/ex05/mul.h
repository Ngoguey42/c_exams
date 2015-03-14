/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 10:58:19 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 11:23:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUL_H
# define MUL_H

#include <stdlib.h>
#include <unistd.h>

typedef struct		s_env
{
	size_t			len;
	int				neg;
	char			*result;
	char			*s1;
	char			*s2;
	char			*s1_head;
	char			*s1_front;
	char			*s2_head;
	size_t			s1_curpad;
	size_t			s2_curpad;
	int				carry;
}					t_env;

int					mul_inputresult(t_env *env);

#endif
