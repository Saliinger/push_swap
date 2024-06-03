/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:39:17 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/23 14:36:34 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push(t_stack **to, t_stack **from)
{
	t_stack	*temp;
	t_stack	*new;

	if (ft_lstsize2(*from) == 0)
		return (-1);
	temp = *from;
	new = ft_lstnew2(temp->number);
	ft_lstadd_front2(to, new);
	*from = (*from)->next;
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_printf("pa\n", 1);
	return (0);
}

int	pb(t_stack **b, t_stack **a)
{
	if (push(b, a) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
