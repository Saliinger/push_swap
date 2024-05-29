/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:59:11 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 15:12:25 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	split_init(char **argv, t_stack **a)
{
	char	**temp;
	int		i;
	t_stack	*new;

	temp = ft_split(argv[1], ' ');
	i = 0;

	while (temp[i])
	{
		new = ft_lstnew2(ft_atoi(temp[i]));
		ft_lstadd_front2(a, new);
		i++;
	}
}

void	unsplit_init(char **argv, t_stack **a)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (argv[i])
	{
		new = ft_lstnew2(ft_atoi(argv[i]));
		ft_lstadd_front2(a, new);
		i++;
	}

}

void	ft_init(int argc, char **argv, t_stack **a)
{
	if (argc > 2)
		unsplit_init(argv, a);
	else if (argc == 2)
		split_init(argv, a);
}
