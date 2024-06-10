/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:43:39 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/10 12:11:04 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_ba(t_stack **a, t_stack **b, t_stack *cheapest)
{
    if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
    {
        while (*b != cheapest)
            rotate_rotate(a, b);
        while (*a != cheapest->target)
            ra(a);
    }
    else
    {
        while (*b != cheapest)
            rb(b);
        if (cheapest->target->above_median == 1)
        {
            while (*a != cheapest->target)
                ra(a);
        }
        else
        {
            while (*a != cheapest->target)
                rra(a);
        }
    }
}

void	reverse_ba(t_stack **a, t_stack **b, t_stack *cheapest)
{
    if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
    {
        while (*b != cheapest)
            rr(a, b);
        while (*a != cheapest->target)
            ra(a);
    }
    else
    {
        while (*b != cheapest)
            rrb(b);
        if (cheapest->target->above_median == 1)
        {
            while (*a != cheapest->target)
                ra(a);
        }
        else
        {
            while (*a != cheapest->target)
                rra(a);
        }
    }

}

void	b_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(b);
	if (cheapest->above_median == 1)
		rotate_ba(a, b, cheapest);
	else
		reverse_ba(a, b, cheapest);
	pa(a, b);
}
