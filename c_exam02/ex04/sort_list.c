/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 09:50:39 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 10:32:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*get_higher(t_list *lst, int (*cmp)(int, int))
{
	t_list		*ret;
	t_list		*cur;

	ret = lst;
	cur = lst->next;
	while (cur)
	{
		if (cmp(ret->data, cur->data) == 0)
			ret = cur;
		cur = cur->next;
	}
	return (ret);
}

void		swap(t_list **tol1, t_list *l1, t_list **tol2, t_list *l2)
{
	t_list *tmp;

	*tol1 = l2;
	*tol2 = l1;
	tmp = l1->next;
	l1->next = l2->next;
	l2->next = tmp;
}

void		list_swap(t_list **alst, t_list *l1, t_list *l2)
{
	t_list	**tol1;
	t_list	**tol2;
	t_list	*cur;

	tol1 = (void*)0;
	tol2 = (void*)0;
	if (*alst == l1)
		tol1 = alst;
	else if (*alst == l2)
		tol2 = alst;
	cur = (*alst);
	while (1)
	{
		if (cur->next == l1)
			tol1 = &cur->next;
		if (cur->next == l2)
			tol2 = &cur->next;
		if (tol1 && tol2)
		{
			swap(tol1, l1, tol2, l2);
			return ;
		}
		cur = cur->next;
	}
}

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list		*cur;
	t_list		*better;

	cur = lst;
	while (cur)
	{
		better = get_higher(cur, cmp);
		if (cur != better)
			list_swap(&lst, cur, better);
		cur = better->next;
	}
	return (lst);
}
