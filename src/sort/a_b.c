/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:24:07 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:27:11 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest) {
    while (*a != cheapest || *b != cheapest->target)
    {
        while (*a != cheapest)
        {
            rotate_rotate(a, b);
        }
        if (*b != cheapest->target)
            rb(b);
    }
}

void reverse_ab(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*a != cheapest || *b != cheapest->target)
    {
        if (*a != cheapest)
            rra(a);
        if (*b != cheapest->target)
            rrb(b);
    }
}

void a_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    cheapest = get_cheapest(a);
    printf("CHEAPEST : number : %d, index : %d, push cost : %d, above median : %d, target : %d\n",
           cheapest->number, cheapest->index, cheapest->push_cost, cheapest->above_median, cheapest->target->number);
    if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
        rotate_ab(a, b, cheapest);
    else if (cheapest->above_median != 1 && cheapest->target->above_median != 1)
        reverse_ab(a, b, cheapest);
    pb(b, a);
    printf("stack a\n");
    ft_print(a);
    printf("stack b\n");
    init_b(b, a);
    ft_print(b);
}
