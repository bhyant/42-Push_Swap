/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:21 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/23 10:23:18 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_int_tab(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*index_array(int *array, int size)
{
	int	*tmp_array;
	int	*new_array;
	int	i;

	i = 0;
	new_array = malloc(sizeof(int) * size);
	tmp_array = malloc(sizeof(int) * size);
	if (!tmp_array || !new_array)
		return (free(tmp_array), free(new_array), NULL);
	while (i < size)
	{
		tmp_array[i] = array[i];
		i++;
	}
	ft_sort_int_tab(tmp_array, size);
	i = 0;
	while (i < size)
	{
		new_array[i] = find_index(tmp_array, size, array[i]);
		i++;
	}
	return (free(tmp_array), new_array);
}

int	find_min_index(t_node *list)
{
	int	min;
	int	index;
	int	min_pos;

	if (!list)
		return (-1);
	min = list->value;
	index = 0;
	min_pos = 0;
	while (list)
	{
		if (list->value < min)
		{
			min = list->value;
			min_pos = index;
		}
		list = list->next;
		index++;
	}
	return (min_pos);
}

void	move_to_top(t_node **list, int index)
{
	int	size;

	size = ft_node_size(*list);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			rotate_a(list, 1);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index > 0)
		{
			reverse_rotate_a(list, 1);
			index--;
		}
	}
}
