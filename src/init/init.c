/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:59:11 by anoukan           #+#    #+#             */
/*   Updated: 2024/05/28 14:31:59 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init(int argc, char **argv, t_stack **a)
{
	if (argc < 2)
		unsplit_init(argv, a);
	else if (argc == 2)
		split_init(argv, a);
	else
		ft_error();
}
