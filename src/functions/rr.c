/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:22:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/04/24 23:23:00 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize2(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast2(head);
	ft_lstadd_front2(stack, tail);
	*stack = head->next;
	tail->next = head;
	return (0);
}

int	rra(t_stack **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_stack **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}

int	rr(t_stack **a, t_stack **b)
{
	if (ft_lstsize2(*a) < 2 || ft_lstsize2(*b) < 2)
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	return (0);
}
