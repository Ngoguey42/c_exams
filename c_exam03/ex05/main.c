/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 11:00:28 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 12:46:41 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mul.h"

void			set_totlen(t_env *env)
{
	env->len = 0;
	env->s1_head = env->s1;
	env->s2_head = env->s2;
	while (*env->s1_head != '\0')
	{
		env->len++;
		env->s1_head++;
	}
	while (*env->s2_head != '\0')
	{
		env->len++;
		env->s2_head++;
	}
	env->s1_head--;
	env->s1_front = env->s1_head;
	env->s2_head--;
	return ;
}

void			ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	return ;
}

int				set_result(t_env *env)
{
	int		i;

	env->result = (char*)malloc(sizeof(char) * (env->len + 1));
	if (env->result == NULL)
		return (1);
	i = 0;
	while (i < (int)env->len)
		env->result[i++] = '0';
	env->result[env->len] = '\0';
	return (0);
}

int				main(int ac, char *av[])
{
	t_env	env;
	char	*ptr;

	env.s1 = av[1];
	env.s2 = av[2];
	env.neg = 0;
	if (*env.s1 == '-')
	{
		env.neg ^= 1;
		env.s1++;
	}
	if (*env.s2 == '-')
	{
		env.neg ^= 1;
		env.s2++;
	}
	set_totlen(&env);
	if (!set_result(&env))
	{
		ptr = env.result;
		(void)mul_inputresult(&env);
		while (*env.result == '0')
			env.result++;
		if (*env.result != '\0' && env.neg)
			ft_putstr("-");
		if (*env.result != '\0')
			ft_putstr(env.result);
		else
			ft_putstr("0");
		free(ptr);
	}
	ft_putstr("\n");
	(void)ac;
	return (0);
}
