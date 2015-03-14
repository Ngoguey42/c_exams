/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphlong.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:59:29 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 11:12:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALPHLONG_H
# define ALPHLONG_H

# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_isspace(char c);
char	ft_tolower(char c);
int		ft_strsplit(char ***words, char *str);
void	move_index(char **words, int i1, int i2);
int		get_better_index(char **words, int i1);
int		is_word2_better(char *w1, char *w2);
int		word_len(char *str);

#endif
