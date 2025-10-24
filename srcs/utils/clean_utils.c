/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:29:18 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/23 22:10:06 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(char **str_values, int *int_values)
{
	free_array(str_values);
	free(int_values);
}

int	clean_array(char **array, char **tmp, int k)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		array[k] = ft_strdup(tmp[i]);
		if (!array[k])
			return (-1);
		free(tmp[i]);
		i++;
		k++;
	}
	free(tmp);
	return (k);
}
