/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:25:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:34:31 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*get_cheapest(t_stack **s)
{
	t_stack	*temp;
	t_stack	*cheapest;

	temp = *s;
	cheapest = temp;
	while (temp)
	{
		if (temp->push_cost < cheapest->push_cost)
		{
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}
