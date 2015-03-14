/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 10:54:57 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 12:51:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUL_H
# define MUL_H

# include <unistd.h>
# include <stdlib.h>

# define MAX(a, b) ((b) < (a) ? (a) : (b))

void	ft_bzero(void *ptr, size_t s);
size_t	ft_strlen(char *ptr);
void	ft_putstr(char *str);
void	ft_memset(void *ptr, unsigned char c, size_t s);
char	*get_estr(int datas[10]);
void	domult(char *orig[2], int datas[10], char *res);
void	input_nbr_pad(char *nb, char *dst, size_t dstlen, int pad);
void	doadd(char *home, char *guest, int nnbr);

#endif
