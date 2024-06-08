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

static long average_node(t_stack **s)
{
    long average;
    long effective;
    long res;

    average = 0;
    effective = 0;
    while (*s)
    {
        average += (*s)->number;
        effective++;
        *s = (*s)->next;
    }
    res = average / effective;
    return (res);
}

void	a_b(t_stack **a, t_stack **b)
{
    long average;
    t_stack *node;

    average = average_node(a);
    node = *a;
	if (node->number < average)
		pb(b, a);
	else
    {
        pb(b, a);
        if(ft_lstsize2(*b) > 2)
            rb(b);
    }
}
