/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oa.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:31:52 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 12:23:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OA_H
# define OA_H

# include <unistd.h>

void        ft_bzero(void *ptr, size_t size);
size_t      ft_strlen(char *str);
int         ft_isspace(char c);
size_t      ft_wordlen(char *str);
int         is_strref_best(char *str_ref, char *str_guest);
void        erase_word(char *wordstart);


#endif
