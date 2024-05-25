/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:22:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:42:26 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
int swap(t_stack **stack_s)
{
    t_stack *top;
    t_stack *next;

    if (ft_lstsize2(*stack_s) < 2)
        return (-1);

    top = *stack_s;
    next = top->next;

    top->next = next->next;
    next->next = top;

    *stack_s = next;

    return (0);
}

int sa(t_stack **a)
{
    if (swap(a) == 0)
        ft_printf("sa\n");
    return (0);
}

int sb(t_stack **b)
{
    if (swap(b) == 0)
        ft_printf("sb\n");
    return (0);
}
