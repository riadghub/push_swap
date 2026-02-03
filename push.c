/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:28:25 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 09:34:00 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile **a, t_pile **b)
{
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_pile **b, t_pile **a)
{
	write(1, "pb\n", 3);
	push(a, b);
}

void	rrr(t_pile **a, t_pile **b)
{
	write(1, "rrr\n", 3);
	reverse_rotate(a);
	reverse_rotate(b);
}

void	push_to_b(t_pile **a, t_pile **b)
{
	int	lim;
	int	lim_up;

	lim = calc_mid(a);
	lim_up = lim;
	while (ft_lstsize(*a) > 3)
	{
		if (!in_lim(a, lim_up))
			lim_up += lim / 2;
		else if ((*a)->content <= lim_up)
			pb(a, b);
		else
			ra(a);
	}
}
