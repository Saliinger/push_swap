/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:20:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:34:59 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack)
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
    free(stack);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

t_stack	*is_max(t_stack **s)
{
	t_stack	*max;
	t_stack	*temp;

	max = ft_lstnew2(INT_MIN);
	temp = *s;
	while (temp)
	{
		if (temp->number > max->number)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*is_min(t_stack **s)
{
	t_stack	*min;
	t_stack	*temp;

	min = ft_lstnew2(INT_MAX);
	temp = *s;
	while (temp)
	{
		if (temp->number < min->number)
			min = temp;
		temp = temp->next;
	}
	return (min);
}
