/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:02:25 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/22 17:50:19 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_node **list_a, t_node	**list_b)
{
	t_node	*list_tmp;

	if (!*list_b)
		return ;
	list_tmp = *list_b;
	*list_b = (*list_b)->next;
	ft_node_add_front(list_a, list_tmp);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_node **list_a, t_node **list_b)
{
	t_node	*list_tmp;

	if (!*list_a)
		return ;
	list_tmp = *list_a;
	*list_a = (*list_a)->next;
	ft_node_add_front(list_b, list_tmp);
	ft_putstr_fd("pb\n", 1);
}
