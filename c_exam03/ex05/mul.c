/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 11:16:22 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 11:45:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mul.h"

static void	addcarry(t_env *env, size_t cur_index)
{
	int		curnbr;

	while (env->carry != 0)
	{
		cur_index--;
		curnbr = env->carry + (env->result[cur_index] - '0');
		env->carry = 0;
		while (curnbr > 9)
		{
			curnbr -= 10;
			env->carry++;
		}
		env->result[cur_index] = (curnbr + '0');
	}
	return ;
}

static void	mul_chars(t_env *env)
{
	int		curnbr;
	size_t	cur_index;

	cur_index = env->len - 1 - env->s1_curpad - env->s2_curpad;
	curnbr = (*env->s1_head - '0') * (*env->s2_head - '0') +
		(env->result[cur_index] - '0');
	env->carry = 0;
	while (curnbr > 9)
	{
		curnbr -= 10;
		env->carry++;
	}
	env->result[cur_index] = (curnbr + '0');
	addcarry(env, cur_index);
	return ;
}

static int	mul_b_member(t_env *env)
{
	env->s1_curpad = 0;
	env->s1_head = env->s1_front;
	while (env->s1_head >= env->s1)
	{
		mul_chars(env);
		env->s1_curpad++;
		env->s1_head--;		
	}
	return (0);
}

int			mul_inputresult(t_env *env)
{
	env->s2_curpad = 0;
	while (env->s2_head >= env->s2)
	{
		(void)mul_b_member(env);
		env->s2_curpad++;
		env->s2_head--;
	}
	return (0);
}
