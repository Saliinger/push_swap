/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:19:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:34:42 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_lstnew2(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(*new_node));
	if (new_node)
	{
		new_node->number = number;
		new_node->next = NULL;
	}
	else
	{
		free(new_node);
		return (NULL);
	}
	return (new_node);
}

int	ft_lstsize2(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front2(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
