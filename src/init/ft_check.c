/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:30:46 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/07 09:16:01 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	double_int(char **argv)
{
	int	i;
	int	j;
	int	num;
	int	check;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		j = 1;
		while (argv[j])
		{
			check = ft_atoi(argv[j]);
			if (num != check || i == j)
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	in_limits(char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi_long(argv[i]);
		if (num <= INT_MAX && num >= INT_MIN)
			i++;
		else
			return (false);
	}
	return (true);
}

static bool	only_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			if (!argv[i][j])
				return (false);
		}
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
	free(num_lst);
}

void	check_in(int argc, char **argv)
{
	char	**num_lst;

	if (argv[1][0] == '\0')
		ft_error();
	if (argc == 2)
		num_lst = ft_split(argv[1], ' ');
	else
		num_lst = &argv[1];
	if (only_number(num_lst) == true && in_limits(num_lst) == true
		&& double_int(num_lst) == true)
	{
		if (argc == 2)
			free_num(num_lst);
	}
	else
	{
		if (argc == 2)
			free_num(num_lst);
		ft_error();
	}
}
