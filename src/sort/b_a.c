/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:43:39 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/20 21:52:40 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/*
void	rotate_ba(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rr(a, b);
}

void	reverse_rotate_ba(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rr(a, b);
}

void	b_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(b);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rotate_ba(a, b, cheapest);
	else if (cheapest->above_median != 1 && cheapest->target->above_median != 1)
        reverse_rotate_ba(a, b, cheapest);
    pa(a,b);
}
*/
void	b_a(t_stack **a, t_stack **b)
{
        while (ft_lstsize2(*b) > 0) {
        t_stack *max_b = is_max(b);
        int max_index = max_b->index;
        int size_b = ft_lstsize2(*b);

        if (max_index <= size_b / 2) {
            while (max_index > 0) {
                rb(b);
                max_index--;
            }
        } else {
            while (max_index < size_b) {
                rrb(b);
                max_index++;
            }
        }
        pa(a, b);
    }
}
