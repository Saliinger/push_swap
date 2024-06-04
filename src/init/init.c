/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:59:11 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/04 14:54:38 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	free_num_lst(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

void	ft_init(int argc, char **argv, t_stack **a)
{
	char	**num_lst;
	int		i;
	t_stack	*new;

	i = 0;
	if (argc == 2)
		num_lst = ft_split(argv[1], ' ');
	else
	{
		num_lst = argv;
		i = 1;
	}
	while (num_lst[i])
	{
		new = ft_lstnew2(ft_atoi(num_lst[i]));
		if (!new)
		{
			ft_free(a);
			ft_error();
		}
		ft_lstadd_back2(a, new);
		i++;
	}
	if (argc == 2)
		free_num_lst(num_lst);
}
