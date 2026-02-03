/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:41:29 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/01/29 11:01:13 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_target(t_pile **a, t_pile **b)
{
	t_pile	*node_b;

	if (!a || !(*a) || !(*a)->next || !b || !(*b) || !(*b)->next)
		return ;
	node_b = *b;
	while (node_b != NULL)
	{
		node_b->target = NULL;
		node_b = node_b->next;
	}
}

t_pile	*get_target(t_pile **a, t_pile *b)
{
	t_pile	*current;
	t_pile	*max;
	t_pile	*target;

	current = *a;
	max = find_max(*a);
	target = max;
	if (max && b->content >= max->content)
		return (find_smallest(*a));
	while (current != NULL)
	{
		if ((current->content < target->content
				&& current->content > b->content))
			target = current;
		current = current->next;
	}
	return (target);
}

void	targeting(t_pile **a, t_pile **b)
{
	t_pile	*current;

	current = *b;
	while (current != NULL)
	{
		current->target = get_target(a, current);
		current = current->next;
	}
}
