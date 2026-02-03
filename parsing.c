/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:38:20 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 12:11:43 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(int argc, char *argv[])
{
	int	i;
	int	k;

	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (!ft_isdigit(argv[i][k]) && k != 0)
				return (write(2, "Error\n", 6), 0);
			k++;
		}
		if ((argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
			|| (!ft_isdigit(argv[i][0]) && argv[i][0] != '-')
			|| ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

int	sub_valid_str(int argc, char *argv[])
{
	int	i;

	(void)argc;
	i = 0;
	if ((argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
		|| (!ft_isdigit(argv[i][0]) && argv[i][0] != '-')
		|| ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	is_valid_str(int argc, char *argv[])
{
	int	i;
	int	k;

	(void)argc;
	i = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (!ft_isdigit(argv[i][k]) && k != 0)
				return (free_all(argv), write(2, "Error\n", 6), 0);
			k++;
		}
		if ((argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
			|| (!ft_isdigit(argv[i][0]) && argv[i][0] != '-')
			|| ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
			return (free_all(argv), write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

int	parsing(int argc, char *argv[])
{
	int		len;
	char	**res;

	len = 0;
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		if (!res || !res[0])
			return (free(res), write(2, "Error\n", 6), 0);
		len = ft_tablen(res);
		if (is_valid_str(len, res))
			return (is_double_str(len, res));
	}
	else
	{
		if (is_valid(argc, argv))
			return (is_double(argc, argv));
	}
	return (0);
}
