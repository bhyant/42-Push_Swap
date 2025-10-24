/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:02:23 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/22 17:50:07 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_node **list_a, int print)
{
	t_node	*before_last;
	t_node	*last;
	t_node	*tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = *list_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	last = tmp->next;
	before_last->next = NULL;
	last->next = *list_a;
	*list_a = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_node **list_b, int print)
{
	t_node	*before_last;
	t_node	*last;
	t_node	*tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = *list_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	last = tmp->next;
	before_last->next = NULL;
	last->next = *list_b;
	*list_b = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **list_a, t_node **list_b)
{
	reverse_rotate_a(list_a, 0);
	reverse_rotate_b(list_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
