/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:56:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/04 14:59:14 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	target_b_init(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*max_a;
	t_stack	*min_a;
	long	match_diff;

	max_a = is_max(a);
	min_a = is_min(a);
	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		match_diff = LONG_MAX;
		temp_b->target = max_a;
		if (temp_b->number > max_a->number || temp_b->number < min_a->number)
			temp_b->target = min_a;
		else
		{
			while (temp_a)
			{
				if (temp_a->number > temp_b->number)
				{
					if (temp_a->number - temp_b->number < match_diff)
					{
						match_diff = temp_a->number - temp_b->number;
						temp_b->target = temp_a;
					}
				}
				temp_a = temp_a->next;
			}
		}
		temp_b = temp_b->next;
	}
}
