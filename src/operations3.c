/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:53:02 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/08 10:25:18 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s, t_bench *bench)
{
	if (!s->a || !s->a->next)
		return ;
	reverse_rotate(&s->a);
	bench->rra_ops += 1;
	print_operation("rra", s);
}

void	rrb(t_stack *s, t_bench *bench)
{
	if (!s->b || !s->b->next)
		return ;
	reverse_rotate(&s->b);
	bench->rrb_ops += 1;
	print_operation("rrb", s);
}

void	rrr(t_stack *s, t_bench *bench)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = 0;
	rotated_b = 0;
	if (s->a && s->a->next)
	{
		reverse_rotate(&s->a);
		rotated_a = 1;
	}
	if (s->b && s->b->next)
	{
		reverse_rotate(&s->b);
		rotated_b = 1;
	}
	if (rotated_a || rotated_b)
	{
		print_operation("rrr", s);
		bench->rrr_ops += 1;
	}
}
