/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:02:12 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/01/29 15:15:27 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_lstnew(int content, int index)
{
	t_pile	*node;

	node = malloc(sizeof(t_pile));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = index;
	node->cost = 0;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

void	costing(t_pile **lst)
{
	int		i;
	t_pile	*node;

	i = 0;
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	node = *lst;
	while (i < ft_lstsize(*lst) / 2 && node != NULL && node->next != NULL)
	{
		node->cost = i;
		node = node->next;
		i++;
	}
	if (ft_lstsize(*lst) % 2 != 0)
	{
		node->cost = i;
		node = node->next;
	}
	while (node != NULL)
	{
		node->cost = i;
		node = node->next;
		i--;
	}
}

void	indexing(t_pile **lst)
{
	int		i;
	t_pile	*node;

	i = 0;
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	node = *lst;
	while (node != NULL && node->next != NULL)
	{
		node->index = i;
		node = node->next;
		i++;
	}
}

void	init_all(t_pile **a, t_pile **b)
{
	indexing(a);
	indexing(b);
	costing(a);
	costing(b);
	targeting(a, b);
}

void	init(t_pile **a, t_pile **b)
{
	push_to_b(a, b);
	sort_three(a);
	init_all(a, b);
}
