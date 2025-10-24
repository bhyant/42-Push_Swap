/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:00:00 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/24 02:56:37 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*create_stack(int *array, int size)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		ft_node_add_back(&stack, ft_node_new(array[i]));
		i++;
	}
	return (stack);
}

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		*int_array;
	int		*indexed_array;
	int		size;
	t_node	*stack_a;
	t_node	*stack_b;

	int_array = parse_args(ac, av);
	if (!int_array)
		return (0);
	size = count_total_args(ac, av);
	if (size == 0)
		return (free(int_array), 0);
	indexed_array = index_array(int_array, size);
	if (!indexed_array)
		return (free(int_array), 1);
	stack_a = create_stack(indexed_array, size);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), 0);
	stack_b = NULL;
	if (!is_sorted(stack_a))
		sort_selector(&stack_a, &stack_b);
	return (ft_node_clear(&stack_a), ft_node_clear(&stack_b),
		free(int_array), free(indexed_array), 0);
}
