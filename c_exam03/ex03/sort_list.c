/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:50:02 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 12:25:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void		swap(t_list **ptoa, t_list *a, t_list **ptob, t_list *b)
{
	if (a->next == b)
	{
		a->next = b->next;
		b->next = a;
		*ptoa = b;
	}
	else if (b->next == a)
	{
		b->next = a->next;
		a->next = b;
		*ptob = a;
	}
	else
	{
		*ptob = b->next;
		*ptoa = b;
		b->next = a;
	}
	return ;
}

static void		doswap(t_list *alst[1], t_list *a, t_list *b)
{
	t_list **ptoa;
	t_list **ptob;
	t_list	*tmp;

	if (*alst == a)
		ptoa = alst;
	if (*alst == b)
		ptob = alst;
	tmp = *alst;
	while (tmp != (void*)0)
	{
		if (tmp->next == a)
			ptoa = &tmp->next;
		if (tmp->next == b)
			ptob = &tmp->next;
		tmp = tmp->next;
	}
	swap(ptoa, a, ptob, b);
	return ;
}

static t_list	*list_at(t_list *alst[1], int ri)
{
	t_list	*tmp;
	int		i;

	tmp = *alst;
	i = 1;
	while (i < ri)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

static void		find_best_for_slot(t_list *alst[1], t_list *slot, int (*cmp)(int, int))
{
	t_list	*tmp;
	t_list	*curbest;

	tmp = slot->next;
	curbest = slot;
	while (tmp != (void*)0)
	{
		if (cmp(curbest->data, tmp->data) == 0)
			curbest = tmp;
		tmp = tmp->next;
	}
	if (curbest != slot)
		doswap(alst, slot, curbest);
	return ;
}

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*alst[1];
	int		i;

	if (lst == (void*)0)
		return (lst);
	*alst = lst;
	i = 1;
	while (1)
	{
		find_best_for_slot(alst, list_at(alst, i), cmp);
		if (list_at(alst, i)->next == (void*)0)
			break ;
		i++;
	}
	return (*alst);
}
