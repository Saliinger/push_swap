/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:31:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:31:55 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_b(t_stack **a, t_stack **b)
{
	index_init(a);
	index_init(b);
	median_init(a);
	median_init(b);
	target_b_init(a, b);
	push_cost_init(b, a);
	cheapest_init(b);
}
