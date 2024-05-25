/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:21:34 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:19:26 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push_cost_init(t_stack **a, t_stack **b)
{
    t_stack *temp_a;
    int size_a = ft_lstsize2(*a);
    int size_b = ft_lstsize2(*b);

    temp_a = *a;
    while (temp_a) {
        temp_a->push_cost = 1;

        if (temp_a->above_median == 1) {
            if (temp_a->target->above_median == 1) {
                temp_a->push_cost += temp_a->index + temp_a->target->index;
            } else {
                temp_a->push_cost += temp_a->index + (size_b - temp_a->target->index);
            }
        } else {
            if (temp_a->target->above_median == 1) {
                temp_a->push_cost += (size_a - temp_a->index) + temp_a->target->index;
            } else {
                temp_a->push_cost += (size_a - temp_a->index) + (size_b - temp_a->target->index);
            }
        }
        temp_a = temp_a->next;
    }
}