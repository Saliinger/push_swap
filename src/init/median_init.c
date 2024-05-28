/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:26:27 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:32:12 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *temp)
{
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
}

void	median_init(t_stack **s)
{
	int		i;
	t_stack	*temp;

	temp = *s;
	i = ft_lstsize2(temp) / 2;
	while (temp)
	{
		if (i >= temp->index)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
	}
}
