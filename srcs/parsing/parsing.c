/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:37 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/23 22:46:50 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*parse_args(int ac, char **av)
{
	char	**str_values;
	int		*int_values;

	if (ac > 1)
	{
		int_values = ft_calloc(sizeof(int), (count_total_args(ac, av)));
		str_values = create_array(ac, av);
		if (!(ft_verif_and_convert(str_values, int_values))
			|| ft_check_doubles(int_values, count_total_args(ac, av)))
		{
			ft_putstr_fd("Error\n", 2);
			free_all(str_values, int_values);
			return (NULL);
		}
	}
	else
		return (NULL);
	free_array(str_values);
	return (int_values);
}
