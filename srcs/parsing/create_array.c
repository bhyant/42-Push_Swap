/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:32:43 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/24 02:48:32 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_verif_and_convert(char **str_values, int *int_values)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (str_values[i])
	{
		if (!(ft_is_number(str_values[i])))
			return (0);
		int_values[i] = ft_atoi_secure(str_values[i], &error);
		if (error)
			return (0);
		i++;
	}
	if (error == 1)
		return (free(int_values), 0);
	i++;
	return (1);
}

char	**create_array(int ac, char **av)
{
	char	**array;
	int		i;
	int		k;
	char	**tmp;
	int		total;

	i = 1;
	k = 0;
	total = count_total_args(ac, av);
	array = malloc(sizeof(char *) * (total + 1));
	if (!array)
		return (NULL);
	while (av[i])
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			return (NULL);
		k = clean_array(array, tmp, k);
		if (k == -1)
			return (NULL);
		i++;
	}
	array[k] = NULL;
	return (array);
}

int	count_total_args(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		total += ft_count_word(av[i], ' ');
		i++;
	}
	return (total);
}
