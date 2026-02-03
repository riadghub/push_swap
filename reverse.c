/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:50:03 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/01/29 09:30:43 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile **a)
{
	write(1, "ra\n", 3);
	rotate(a);
	indexing(a);
}

void	rb(t_pile **b)
{
	write(1, "rb\n", 3);
	rotate(b);
	indexing(b);
}

void	rr(t_pile **a, t_pile **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
	indexing(a);
	indexing(b);
}

void	rra(t_pile **a)
{
	write(1, "rra\n", 4);
	reverse_rotate(a);
	indexing(a);
}

void	rrb(t_pile **b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(b);
	indexing(b);
}
