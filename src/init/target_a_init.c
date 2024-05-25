/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:25:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:30:08 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void target_a_init(t_stack **a, t_stack **b)
{
    t_stack *temp_a = *a;
    t_stack *temp_b;
    t_stack *max_b;
    t_stack *min_b;
    long match;

    max_b = is_max(b);
    min_b = is_min(b);

    while (temp_a) {
        temp_b = *b;
        match = LONG_MAX;
        temp_a->target = max_b; // Default to the max in b if no greater number is found

        if (temp_a->number > max_b->number) {
            temp_a->target = min_b;
        } else {
            while (temp_b) {
                if (temp_a->number < temp_b->number && temp_b->number < match) {
                    match = temp_b->number;
                    temp_a->target = temp_b;
                }
                temp_b = temp_b->next; // Move to the next node in stack b
            }
        }
        temp_a = temp_a->next; // Move to the next node in stack a
    }
}
