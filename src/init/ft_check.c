/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:30:46 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/29 13:52:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// check :
// - if only number
// - if <= INT_MAX || >= INT_MIN

static bool	in_limits(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ft_printf("number : %d\n", ft_atoi(argv[i]));
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			ft_printf("false\n");
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	only_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (false);
			else
				j++;
		}
		i++;
	}
	return (true);
}

static void	free_num(char **num_lst)
{
	int	i;

	i = 0;
	while (num_lst[i])
	{
		free(num_lst[i]);
		i++;
	}
}

void	check_in(int argc, char **argv)
{
	char	**num_lst;

	if (argc == 2)
		num_lst = ft_split(argv[1], ' ');
	else
		num_lst = argv;
	if (only_number(num_lst) == false || in_limits(num_lst) == false)
	{
		free_num(num_lst);
		ft_error();
	}
	free_num(num_lst);
}
