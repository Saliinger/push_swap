/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:20:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/29 17:23:09 by anoukan          ###   ########.fr       */
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
    int     max;
	t_stack	*stack_max;
	t_stack	*temp;

	max = INT_MIN;
	temp = *s;
	while (temp)
	{
		if (temp->number > max)
        {
            max = temp->number;
            stack_max = temp;
        }
		temp = temp->next;
	}
	return (stack_max);
}

t_stack	*is_min(t_stack **s)
{
	int		min;
	t_stack	*stack_min;
	t_stack	*temp;

	min = INT_MAX;
	temp = *s;
	while (temp)
	{
		if (temp->number < min)
		{
			stack_min = temp;
			min = temp->number;
		}
		temp = temp->next;
	}
	return (stack_min);
}

void ft_print(t_stack **stack)
{
    while (*stack)
    {
        ft_printf("number : %d\n", (*stack)->number);
        *stack =(*stack)->next;
    }
}
