/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:32:04 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 10:13:43 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_space(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int			i;
	int			minus;
	long long	res;

	i = 0;
	minus = 0;
	res = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			minus++;
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		res = res * 10 + nptr[i++] - '0';
	}
	if (minus % 2 != 0)
		res *= -1;
	return (res);
}

void	free_list(t_pile **lst)
{
	t_pile	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	sort_all(t_pile **a, t_pile **b)
{
	t_pile	*cheapest;

	init(a, b);
	while (*b)
	{
		init_all(a, b);
		cheapest = find_cheapest(b);
		while (*b != cheapest)
		{
			if (cheapest->index < ft_lstsize(*b) / 2)
				rb(b);
			else
				rrb(b);
			init_all(a, b);
		}
		while (*a != cheapest->target)
		{
			if (cheapest->target->index < ft_lstsize(*a) / 2)
				ra(a);
			else
				rra(a);
			init_all(a, b);
		}
		pa(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (parsing(argc, argv))
	{
		add_to_lst(argc, argv, &a);
		if (ft_lstsize(a) == 1)
			return (free_list(&a), 0);
		if (ft_lstsize(a) == 2)
		{
			sort_two(&a);
			return (free_list(&a), 0);
		}
		if (!is_sorted(&a))
			sort_all(&a, &b);
		sort_a(&a);
		free_list(&a);
		free_list(&b);
	}
	return (0);
}
