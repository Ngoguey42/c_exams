/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 09:34:46 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 09:44:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*get_higher(int *tab, unsigned int size)
{
	int		val;
	int		*ret;

	val = *tab;
	ret = (void*)0;
	while (size)
	{
		if (*tab < val)
		{
			ret = tab;
			val = *ret;
		}
		tab++;
		size--;
	}
	return (ret);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int		*lw;
	int		tmp;

	while (size)
	{
		lw = get_higher(tab, size);
		if (lw)
		{
			tmp = *tab;
			*tab = *lw;
			*lw = tmp;
		}
		tab++;
		size--;
	}
	return ;
}
