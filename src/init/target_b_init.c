/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:56:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/07 09:15:28 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	calcul_b(t_stack *a, t_stack *b, long *match_diff)
{
	if (a->number > b->number)
	{
		if (a->number - b->number < *match_diff)
		{
			*match_diff = a->number - b->number;
			b->target = a;
		}
	}
}

void	target_b_init(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	long	match_diff;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		match_diff = LONG_MAX;
		temp_b->target = is_max(a);
		if (temp_b->number > is_max(a)->number
			|| temp_b->number < is_min(a)->number)
			temp_b->target = is_min(a);
		else
		{
			while (temp_a)
			{
				calcul_b(temp_a, temp_b, &match_diff);
				temp_a = temp_a->next;
			}
		}
		temp_b = temp_b->next;
	}
}
