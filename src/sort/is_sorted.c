/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:34:35 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_sorted_big_to_low(t_stack **a)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = temp->number;
	while (temp)
	{
		if (i < temp->number)
			return (false);
		i = temp->number;
		temp = temp->next;
	}
	return (true);
}

bool	is_sorted(t_stack **a)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = temp->number;
	while (temp)
	{
		if (i > temp->number)
			return (false);
		i = temp->number;
		temp = temp->next;
	}
	return (true);
}
