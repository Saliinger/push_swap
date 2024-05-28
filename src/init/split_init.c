/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:05:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:32:22 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	split_init(char **argv, t_stack **a)
{
	char	**temp;
	int		i;
	t_stack	*new;
	int		j;

	temp = ft_split(argv[1], ' ');
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] >= '0' && temp[i][j] <= '9')
				j++;
			else
				ft_error();
		}
		i++;
	}
	i = 0;
	while (temp[i])
	{
		new = ft_lstnew2(ft_atoi(temp[i]));
		ft_lstadd_front2(a, new);
		i++;
	}
}
