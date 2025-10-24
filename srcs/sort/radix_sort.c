/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:22:25 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/23 10:22:33 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_find_max(t_node *lst)
{
	int	max;
	int	bits;

	bits = 0;
	if (!lst)
		return (0);
	max = (lst->value);
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

static void	apply_radix_sort(t_node **list_a, t_node **list_b, int bits)
{
	int	size;
	int	j;
	int	value;
	int	current_bit;

	j = 0;
	size = ft_node_size(*list_a);
	while (j < size)
	{
		value = (*list_a)->value;
		current_bit = (value >> bits) & 1;
		if (current_bit == 0)
			push_b(list_a, list_b);
		else
			rotate_a(list_a, 1);
		j++;
	}
}

void	radix_sort(t_node **list_a, t_node **list_b)
{
	int	i;
	int	max_bits;

	i = 0;
	max_bits = ft_find_max(*list_a);
	while (i < max_bits)
	{
		apply_radix_sort(list_a, list_b, i);
		while (*list_b != NULL)
			push_a(list_a, list_b);
		i++;
	}
}
