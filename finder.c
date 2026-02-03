/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:42:04 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/01/29 15:08:07 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*find_max(t_pile *lst)
{
	t_pile	*max;

	max = lst;
	while (lst != NULL)
	{
		if (lst->content > max->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_pile	*find_next_max(t_pile *lst, t_pile *b)
{
	t_pile	*max;

	max = find_max(lst);
	if (max && b->content >= max->content)
		return (find_smallest(lst));
	while (lst != NULL)
	{
		if (lst->content < max->content && lst->content > b->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_pile	*find_smallest(t_pile *lst)
{
	t_pile	*min;

	min = lst;
	while (lst != NULL)
	{
		if (lst->content < min->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

int	calculate_cost(t_pile *node)
{
	int	cost;

	cost = node->cost;
	if (node->target)
		cost += node->target->cost;
	else
		cost += INT_MAX;
	return (cost);
}

t_pile	*find_cheapest(t_pile **b)
{
	t_pile	*res;
	t_pile	*node;
	int		cost;
	int		tmp_cost;

	res = *b;
	node = *b;
	cost = calculate_cost(res);
	while (node)
	{
		tmp_cost = calculate_cost(node);
		if (tmp_cost < cost)
		{
			cost = tmp_cost;
			res = node;
		}
		node = node->next;
	}
	return (res);
}
