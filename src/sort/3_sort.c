/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:24:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:32:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void three_sort(t_stack **a)
{
    if (ft_lstsize2(*a) != 3)
        return;

    int first = (*a)->number;
    int second = (*a)->next->number;
    int third = (*a)->next->next->number;

    if (first > second && second < third && first < third) // 2 1 3 -> 1 2 3
    {
        sa(a);
    }
    else if (first > second && second > third) // 3 2 1 -> 1 2 3
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third) // 3 1 2 -> 1 2 3
    {
        ra(a);
    }
    else if (first < second && second > third && first < third) // 1 3 2 -> 1 2 3
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third) // 2 3 1 -> 1 2 3
    {
        rra(a);
    }
}
