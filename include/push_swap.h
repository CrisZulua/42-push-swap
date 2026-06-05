/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:40:51 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/08 14:11:14 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "parser.h"
# include "libft.h"

typedef enum e_disorder_level
{
	DISORDER_LOW,
	DISORDER_MEDIUM,
	DISORDER_HIGH
}	t_disorder_level;

t_node	*new_node(int value);
void	stack_push(t_node **stack, t_node *node);
t_node	*stack_pop(t_node **stack);
int		stack_size(t_node *stack);
int		stack_peek(t_node *stack);
void	free_stack(t_node **stack);
void	reverse_rotate(t_node **stack);
void	rotate(t_node **stack);

void	op_ss(t_stack *s, t_bench *bench);
void	op_sb(t_stack *s, t_bench *bench);
void	op_sa(t_stack *s, t_bench *bench);
void	rb(t_stack *s, t_bench *bench);
void	ra(t_stack *s, t_bench *bench);
void	rr(t_stack *s, t_bench *bench);
void	op_pa(t_stack *s, t_bench *bench);
void	op_pb(t_stack *s, t_bench *bench);
void	rra(t_stack *s, t_bench *bench);
void	rrb(t_stack *s, t_bench *bench);
void	rrr(t_stack *s, t_bench *bench);
void	print_operation(const char *op, t_stack *s);

double	compute_disorder_index(t_node *stack);
void	sort_adaptative(t_stack *stack, t_bench *bench);

void	sort_simple(t_stack *stack, t_bench *bench);
void	rotate_helper_to_top(t_stack *s, t_bench *bench, int min_pos);
void	rotate_helper_to_top_b(t_stack *s, t_bench *bench, int min_pos);

void	sort_medium(t_stack *stack, t_bench *bench);
int		ft_sqrt(int n);
void	assign_indices(t_node *stack);
void	push_back_sorted(t_stack *s, t_bench *bench);
int		find_minimum_index_pos(t_node *stack);
void	push_chunk_to_b(t_stack *s, t_bench *bench, int min_idx, int max_idx);
int		find_max_index_pos(t_node *stack);

void	sort_complex(t_stack *stack, t_bench *bench);
int		is_sorted(t_node *stack);
void	ft_assign_index(t_node *stack, int stack_size);

void	ft_init_bench(t_bench *bench, double disorder_idx);
void	ft_print_bench_mode(t_stack *stack, t_bench *bench);

#endif
