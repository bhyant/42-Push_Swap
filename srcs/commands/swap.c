/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:02:30 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/22 17:49:31 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_node **list_a, int print)
{
	int	tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = (*list_a)->value;
	(*list_a)->value = (*list_a)->next->value;
	(*list_a)->next->value = tmp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_node **list_b, int print)
{
	int	tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = (*list_b)->value;
	(*list_b)->value = (*list_b)->next->value;
	(*list_b)->next->value = tmp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **list_a, t_node **list_b)
{
	swap_a(list_a, 0);
	swap_b(list_b, 0);
	ft_putstr_fd("ss\n", 1);
}
