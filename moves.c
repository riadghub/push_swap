/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:35:39 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/01/29 09:35:50 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **a)
{
	int	tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
}

void	push(t_pile **to, t_pile **from)
{
	t_pile	*tmp;

	if (!from || !(*from))
		return ;
	tmp = (*from)->next;
	ft_lstadd_front(to, (*from));
	*from = tmp;
}

void	rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = ft_lstlast(*a);
	last->next = tmp;
}

void	reverse_rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*first;
	t_pile	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = *a;
	first = *a;
	last = ft_lstlast(*a);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*a = last;
}
