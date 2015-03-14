/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:18:29 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:30:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_H
# define COUNT_H
# define BUFFSIZE 50

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t		ft_strlen(char *s);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strdup(char *src);
void		ft_putchar(char c);
void		ft_putstr(const char *s);
void		ft_bzero(void *ptr, size_t n);

int			is_grid_valid(int data[2], char ***grid, int ac, char **av);
int			fill_grid(char **grid, char *str, int fd);

void		print_grid(char **grid, int data[2]);
int			edit_grid(char **grid, int data[2]);

#endif
