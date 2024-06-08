/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:23:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/04 14:53:48 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	order(t_stack **s)
{
	t_stack	*min;

	min = is_min(s);
	if (min->above_median)
	{
		while (*s != min)
			ra(s);
	}
	else
	{
		while (*s != min)
			rra(s);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize2(*a) <= 3)
		three_sort(a);
	else if (ft_lstsize2(*a) > 3)
	{
		while (ft_lstsize2(*a) >= 3)
			a_b(a, b);
		three_sort(a);
		while (*b)
		{
			init_b(a, b);
			b_a(a, b);
		}
	}
	order(a);
}
