/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:27:39 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/01/29 09:34:23 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_pile **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_pile **a, t_pile **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
