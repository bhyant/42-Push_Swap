/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:03:42 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/23 23:44:59 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* ************************************************************************** */
/*                                LISTE UTILS                                 */
/* ************************************************************************** */

t_node	*ft_node_new(int value);
void	ft_node_add_back(t_node **lst, t_node *new);
void	ft_node_add_front(t_node **lst, t_node *new);
size_t	ft_node_size(t_node *lst);
t_node	*ft_node_last(t_node *lst);
void	ft_node_clear(t_node **lst);

/* ************************************************************************** */
/*                                PARSING                                     */
/* ************************************************************************** */

bool	ft_is_number(char *str);
bool	ft_check_doubles(int *tab, int size);
int		ft_atoi_secure(char *str, int *error_flag);
int		*parse_args(int ac, char **av);
int		count_total_args(int ac, char **av);
int		ft_count_word(char const *str, char c);
int		ft_verif_and_convert(char **str_values, int *int_values);
char	**create_array(int ac, char **av);

/* ************************************************************************** */
/*                                CLEAN UTILS                                 */
/* ************************************************************************** */

void	print_stack(t_node *stack, char *name);
void	free_array(char **tab);
void	free_all(char **str_tab, int *int_tab);
int		clean_array(char **array, char **tmp, int k);

/* ************************************************************************** */
/*                                COMMANDS                                    */
/* ************************************************************************** */

void	push_a(t_node **list_a, t_node	**list_b);
void	push_b(t_node **list_a, t_node **list_b);
void	swap_a(t_node **list_a, int print);
void	swap_b(t_node **list_b, int print);
void	ss(t_node **list_a, t_node **list_b);
void	rotate_a(t_node **list_a, int print);
void	rotate_b(t_node **list_b, int print);
void	rr(t_node **list_a, t_node **list_b);
void	reverse_rotate_a(t_node **list_a, int print);
void	reverse_rotate_b(t_node **list_b, int print);
void	rrr(t_node **list_a, t_node **list_b);

/* ************************************************************************** */
/*                                  SORT                                      */
/* ************************************************************************** */

void	radix_sort(t_node **list_a, t_node **list_b);
int		*index_array(int *tab, int size);
void	move_to_top(t_node **list, int index);
int		find_min_index(t_node *list);
void	sort_selector(t_node **list_a, t_node **list_b);

#endif
