/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:21:34 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/04 16:38:51 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	calcul_above(t_stack *node, int size_a, int size_b)
{
	if (node->target->above_median == 1)
		node->push_cost += (size_a - node->index) + node->target->index;
	else
		node->push_cost += (size_a - node->index) + (size_b
				- node->target->index);
}

static void	calcul_under(t_stack *node, int size_a, int size_b)
{
	if (node->target->above_median == 1)
		node->push_cost += (size_a - node->index) + node->target->index;
	else
		node->push_cost += (size_a - node->index) + (size_b
				- node->target->index);
}

void	push_cost_init(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize2(*a);
	size_b = ft_lstsize2(*b);
	temp_a = *a;
	while (temp_a)
	{
		temp_a->push_cost = 1;
		if (temp_a->above_median == 1)
			calcul_above(temp_a, size_a, size_b);
		else
			calcul_under(temp_a, size_a, size_b);
		temp_a = temp_a->next;
	}
}
