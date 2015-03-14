/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diam.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 11:23:11 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 12:45:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAM_H
# define DIAM_H

# include <stdlib.h>

typedef struct	s_pair
{
	int			a;
	int			b;
	int			visited;
}				t_pair;

void			ft_bzero(void *ptr, size_t size);
void			ft_bmone(void *ptr, size_t size);
int				ft_isdigit(char c);
int				get_number(char **c);
int				find_max_jumps(t_pair *pairs, int maxlnknb);

void			insert_trace(int *trace, int i);
int				is_in_trace(int *trace, int i);
void			rm_in_trace(int *trace, int i);

#endif
