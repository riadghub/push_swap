/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:34:46 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 10:00:07 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_pile **lst, t_pile *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_pile	*ft_lstlast(t_pile *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	add_to_lst(int argc, char *argv[], t_pile **lst)
{
	if (!lst)
		return ;
	if (parsing(argc, argv))
	{
		if (argc == 2)
			adding_str(argc, argv, lst);
		else if (argc > 2)
			adding_arg(argc, argv, lst);
	}
}

int	is_sorted(t_pile **lst)
{
	int		i;
	int		val;
	t_pile	*node;

	i = 0;
	val = 0;
	if (!lst || !(*lst) || !(*lst)->next)
		return (0);
	node = *lst;
	while (i < ft_lstsize(*lst))
	{
		while (node != NULL && node->next != NULL)
		{
			if (node->index == i)
				val = node->content;
			if (node->next->index > i && val > node->next->content)
				return (0);
			node = node->next;
		}
		node = *lst;
		i++;
	}
	return (1);
}
