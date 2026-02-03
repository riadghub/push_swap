/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:40:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 09:19:59 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_lim(t_pile **a, int lim)
{
	t_pile	*node_a;

	node_a = *a;
	while (node_a != NULL)
	{
		if (node_a->content <= lim)
			return (1);
		node_a = node_a->next;
	}
	return (0);
}

int	calc_mid(t_pile **a)
{
	int		count;
	t_pile	*node_a;

	count = 0;
	node_a = *a;
	while (node_a != NULL && node_a->next != NULL)
	{
		if (node_a->content > 0)
			count += node_a->content;
		node_a = node_a->next;
	}
	if (count != 0 && ft_lstsize(*a) != 0)
		count /= ft_lstsize(*a);
	return (count);
}

void	sort_two(t_pile **lst)
{
	t_pile	*a;

	if (!lst || !(*lst))
		return ;
	a = *lst;
	if (a->content > a->next->content)
		sa(lst);
}

void	sort_three(t_pile **lst)
{
	t_pile	*f;
	t_pile	*second;
	t_pile	*third;

	if (!lst || !(*lst))
		return ;
	f = *lst;
	second = f->next;
	third = second->next;
	if (f->content > second->content && f->content < third->content)
		sa(lst);
	else if (f->content > second->content && second->content > third->content)
	{
		sa(lst);
		rra(lst);
	}
	else if (f->content > second->content)
		ra(lst);
	else if (second->content > third->content && f->content < third->content)
	{
		sa(lst);
		ra(lst);
	}
	else if (f->content > third->content)
		rra(lst);
}

void	sort_a(t_pile **a)
{
	while ((*a) != find_smallest(*a))
	{
		if (find_smallest(*a)->index <= ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
		indexing(a);
		costing(a);
	}
}
