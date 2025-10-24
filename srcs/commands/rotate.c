/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:02:28 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/22 17:49:54 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_node **list_a, int print)
{
	t_node	*tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = NULL;
	ft_node_add_back(list_a, tmp);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_node **list_b, int print)
{
	t_node	*tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = NULL;
	ft_node_add_back(list_b, tmp);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **list_a, t_node **list_b)
{
	rotate_a(list_a, 0);
	rotate_b(list_b, 0);
	ft_putstr_fd("rr\n", 1);
}
