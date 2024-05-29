/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:23:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/29 17:07:36 by anoukan          ###   ########.fr       */
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

// static void	ft_print(t_stack **s)
// {
// 	while (*s)
// 	{
// 		ft_printf("%d\n", (*s)->number);
// 		(*s) = (*s)->next;
// 	}
// }

void	ft_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize2(*a) <= 3)
		three_sort(a);
	else if (ft_lstsize2(*a) > 3)
	{
		pb(b, a);
		pb(b, a);
		while (ft_lstsize2(*a) >= 4)
		{
			init_a(a, b);
			a_b(a, b);
		}
		three_sort(a);
		init_b(a, b);
		while (*b)
		{
			init_b(a, b);
			b_a(a, b);
		}
	}
	order(a);
	ft_free(a);
	ft_free(b);
}
