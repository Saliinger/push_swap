/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:25:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/04 14:58:33 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	target_a_init(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*max_b;
	t_stack	*min_b;
	long	match_diff;

	max_b = is_max(b);
	min_b = is_min(b);
	temp_a = *a;
	while (temp_a)
	{
		temp_b = *b;
		match_diff = LONG_MAX;
		temp_a->target = max_b;
		if (temp_a->number > max_b->number || temp_a->number < min_b->number)
			temp_a->target = max_b;
		else
		{
			while (temp_b)
			{
				if (temp_a->number > temp_b->number)
				{
					if (temp_a->number - temp_b->number < match_diff)
					{
						match_diff = temp_a->number - temp_b->number;
						temp_a->target = temp_b;
					}
				}
				temp_b = temp_b->next;
			}
		}
		temp_a = temp_a->next;
	}
}
