/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:26:27 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:18:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	median_init(t_stack **s)
{
	int		i;
	int		j;
	t_stack	*temp;

	j = 0;
	temp = *s;
	i = ft_lstsize2(temp) / 2;
	while (temp)
	{
		if (i > j)
			temp->above_median = 1;
		else
			temp->above_median = 0;
        temp = temp->next;
	}
}
