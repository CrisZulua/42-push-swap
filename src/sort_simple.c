/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:16:27 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/13 09:33:14 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_value_pos(t_node *stack)
{
	t_node	*current_node;
	int		min_pos;
	int		min_value;
	int		pos;

	current_node = stack;
	min_pos = 0;
	pos = 0;
	min_value = current_node->value;
	while (current_node)
	{
		if (current_node->value < min_value)
		{
			min_value = current_node->value;
			min_pos = pos;
		}
		pos++;
		current_node = current_node->next;
	}
	return (min_pos);
}

void	rotate_helper_to_top(t_stack *s, t_bench *bench, int min_pos)
{
	int	i;
	int	size;

	size = s->size_a;
	if (min_pos <= (size / 2))
	{
		i = 0;
		while (i < min_pos)
		{
			ra(s, bench);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - min_pos)
		{
			rra(s, bench);
			i++;
		}
	}
}

void	rotate_helper_to_top_b(t_stack *s, t_bench *bench, int min_pos)
{
	int	i;
	int	size;

	size = s->size_b;
	if (min_pos <= (size / 2))
	{
		i = 0;
		while (i < min_pos)
		{
			rb(s, bench);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - min_pos)
		{
			rrb(s, bench);
			i++;
		}
	}
}

void	sort_simple(t_stack *stack, t_bench *bench)
{
	int		counter;
	int		min_pos;

	if (!stack)
		return ;
	if (is_sorted(stack->a))
		return ;
	counter = stack->size_a;
	while (counter > 0)
	{
		min_pos = min_value_pos(stack->a);
		rotate_helper_to_top(stack, bench, min_pos);
		op_pb(stack, bench);
		counter--;
	}
	counter = stack->size_b;
	while (counter > 0)
	{
		op_pa(stack, bench);
		counter--;
	}
}
