/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:42:42 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/08 10:22:07 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(const char *op, t_stack *s)
{
	int	i;

	i = 0;
	while (op[i])
		i++;
	write(1, op, i);
	write(1, "\n", 1);
	s -> total_ops++;
}

static void	swap_values(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	op_sa(t_stack *s, t_bench *bench)
{
	if (!s->a || !s->a->next)
		return ;
	swap_values(s->a);
	bench->sa_ops += 1;
	print_operation("sa", s);
}

void	op_sb(t_stack *s, t_bench *bench)
{
	if (!s->b || !s->b->next)
		return ;
	swap_values(s->b);
	bench->sb_ops += 1;
	print_operation("sb", s);
}

void	op_ss(t_stack *s, t_bench *bench)
{
	swap_values(s->a);
	swap_values(s->b);
	bench->ss_ops += 1;
	print_operation("ss", s);
}
