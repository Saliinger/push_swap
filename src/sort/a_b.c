/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:24:07 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/29 15:19:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest)
		ra(a);
	if (cheapest->target->above_median == 1)
	{
		while ((*b)->number != cheapest->target->number)
			rb(b);
	}
	else
	{
		while ((*b)->number != cheapest->target->number)
			rrb(b);
	}
}

void	reverse_ab(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest)
		rra(a);
	if (cheapest->target->above_median == 1)
	{
		while ((*b)->number != cheapest->target->number)
			rb(b);
	}
	else
	{
		while ((*b)->number != cheapest->target->number)
			rrb(b);
	}
}

void	a_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(a);
	if (cheapest->above_median == 1)
		rotate_ab(a, b, cheapest);
	else
		reverse_ab(a, b, cheapest);
	pb(b, a);
}
