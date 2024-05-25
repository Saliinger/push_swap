/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:25:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:43:16 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*get_cheapest(t_stack **s)
{
    t_stack *temp = *s;
    t_stack *cheapest = temp;

    while (temp) {
        if (temp->push_cost < cheapest->push_cost) {
            cheapest = temp;
        }
        temp = temp->next;
    }
    return cheapest;
}
