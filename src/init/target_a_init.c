/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:25:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/04 16:38:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	calcul_a(t_stack *a, t_stack *b, long *match_diff)
{
	if (a->number > b->number)
	{
		if (a->number - b->number < *match_diff)
		{
			*match_diff = a->number - b->number;
			a->target = b;
		}
	}
}

void	target_a_init(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	long	match_diff;

	temp_a = *a;
	while (temp_a)
	{
		temp_b = *b;
		match_diff = LONG_MAX;
		temp_a->target = is_max(b);
		if (temp_a->number > is_max(b)->number
			|| temp_a->number < is_min(b)->number)
			temp_a->target = is_max(b);
		else
		{
			while (temp_b)
			{
				calcul_a(temp_a, temp_b, &match_diff);
				temp_b = temp_b->next;
			}
		}
		temp_a = temp_a->next;
	}
}
