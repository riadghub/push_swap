/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:39:40 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 12:11:22 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	adding_str(int argc, char *argv[], t_pile **lst)
{
	char	**split;
	int		value;
	int		i;

	(void)argc;
	split = ft_split(argv[1], ' ');
	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		value = ft_atoi(split[i]);
		ft_lstadd_back(lst, ft_lstnew(value, i));
		i++;
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	adding_arg(int argc, char *argv[], t_pile **lst)
{
	int	value;
	int	i;

	if (!lst || argc == 1)
		return ;
	i = ft_tablen(argv) - 1;
	if (!argv || !lst)
		return ;
	while (argv[i] && i > 0)
	{
		value = ft_atoi(argv[i]);
		ft_lstadd_front(lst, ft_lstnew(value, i - 1));
		i--;
	}
}

int	is_double(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (is_valid(argc, argv))
	{
		while (i < argc)
		{
			k = 1;
			while (k < argc)
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[k]) && i != k)
					return (write(2, "Error\n", 6), 0);
				k++;
			}
			i++;
		}
	}
	return (1);
}

int	is_double_str(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 0;
	if (is_valid(argc, argv))
	{
		while (i < argc)
		{
			k = 1;
			while (k < argc)
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[k]) && i != k)
					return (free_all(argv), write(2, "Error\n", 6), 0);
				k++;
			}
			i++;
		}
	}
	free_all(argv);
	return (1);
}
