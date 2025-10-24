/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:11:30 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/23 23:32:37 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_node **list)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*list)->value;
	val2 = (*list)->next->value;
	val3 = (*list)->next->next->value;
	if (val1 > val2 && val1 > val3)
		rotate_a(list, 1);
	else if (val2 > val1 && val2 > val3)
		reverse_rotate_a(list, 1);
	if (val1 > val2)
		swap_a(list, 1);
}

static void	sort_four(t_node **list_a, t_node **list_b)
{
	int	min_index;

	min_index = find_min_index(*list_a);
	move_to_top(list_a, min_index);
	push_b(list_a, list_b);
	sort_three(list_a);
	push_a(list_a, list_b);
}

static void	sort_five(t_node **list_a, t_node **list_b)
{
	int	min_index;

	while (ft_node_size(*list_a) > 3)
	{
		min_index = find_min_index(*list_a);
		move_to_top(list_a, min_index);
		push_b(list_a, list_b);
	}
	sort_three(list_a);
	while (*list_b)
		push_a(list_a, list_b);
}

void	sort_selector(t_node **list_a, t_node **list_b)
{
	int	size;

	size = ft_node_size(*list_a);
	if (size <= 1)
		return ;
	else if (size == 2)
		swap_a(list_a, 1);
	else if (size == 3)
		sort_three(list_a);
	else if (size == 4)
		sort_four(list_a, list_b);
	else if (size == 5)
		sort_five(list_a, list_b);
	else
		radix_sort(list_a, list_b);
}
