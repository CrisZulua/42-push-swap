/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:57:47 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/08 14:13:38 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *s, t_bench *bench)
{
	t_node	*pop_node;

	if (!s->b)
		return ;
	pop_node = stack_pop(&s->b);
	stack_push(&s->a, pop_node);
	s->size_a++;
	s->size_b--;
	bench->pa_ops += 1;
	print_operation("pa", s);
}

void	op_pb(t_stack *s, t_bench *bench)
{
	t_node	*pop_node;

	if (!s->a)
		return ;
	pop_node = stack_pop(&s->a);
	stack_push(&s->b, pop_node);
	s->size_a--;
	s->size_b++;
	bench->pb_ops += 1;
	print_operation("pb", s);
}

void	ra(t_stack *s, t_bench *bench)
{
	if (!s->a || !s->a->next)
		return ;
	rotate(&s->a);
	bench->ra_ops += 1;
	print_operation("ra", s);
}

void	rb(t_stack *s, t_bench *bench)
{
	if (!s->b || !s->b->next)
		return ;
	rotate(&s->b);
	bench->rb_ops += 1;
	print_operation("rb", s);
}

void	rr(t_stack *s, t_bench *bench)
{
	rotate(&s->a);
	rotate(&s->b);
	bench->rr_ops += 1;
	print_operation("rr", s);
}
