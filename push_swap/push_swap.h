/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:07:08 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/18 17:43:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// -LIBRARIES-
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// -STRUCT-
typedef struct s_node
{
	int				value;
	int				rank;
	int				cost;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*twin;
}	t_node;

// -STACK INIT-
t_node	*make_stack(char **av, t_node **stack);
char	**make_new_av(char **av);
t_node	*fill_stack(char **new_av, t_node **stack);
long	long_atoi(char *str);

// -ERROR HANDLING-
int		param_error(char **new_av);
int		too_long(char **new_av);
void	check_dup(t_node *stack);
void	error_procedure(char **new_av);

// -NODE HANDLING-
t_node	*new_node(int value);
t_node	*last_node(t_node *stack);
void	add_back(t_node **stack, t_node *node);
void	add_front(t_node **stack, t_node *node);
void	free_stack(t_node **stack);

// -STACK TOOLS-
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
t_node	*find_small(t_node *stack);

// -INITIALISE STACK VALUES-
void	rankit(t_node *stack);
void	find_twin(t_node **stack_a, t_node **stack_b);
void	set_cost(t_node *stack_b);
void	calc_cost(int a, int b, t_node *node);

// -ALGORITHM BASE-
void	push_swap(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_big(int base_size, t_node **stack_a, t_node **stack_b);

// -ARRAY SORTING-
int		*make_arr(t_node *stack_b);
int		*bubble_sort(int *arr, int size);

// -ALGORITHM TOOLS-
void	push_to_b(int base_size, int *arr, t_node **stack_a, t_node **stack_b);
int		chunk_size(int base_size);
t_node	*find_cheap(t_node *stack);
void	final_sort(t_node **stack);
void	push_to_a(t_node *cheap, t_node **stack_a, t_node **stack_b);
void	bot_op(t_node *twin, t_node *cheap, t_node **stack_a, t_node **stack_b);
void	top_op(t_node *twin, t_node *cheap, t_node **stack_a, t_node **stack_b);
void	sep_op(t_node *twin, t_node *cheap, t_node **stack_a, t_node **stack_b);

// -OPERATIONS-
// Swap:
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
// Rotate:
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
// Reverse Rotate:
void	rev_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
// Push:
void	push(t_node **stack_src, t_node **stack_dst);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);

#endif
