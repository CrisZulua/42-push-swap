/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:15:08 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/15 12:34:32 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
The formula (size - 1) >> max_bits shifts right until the
number becomes 0, count shifts = bits needed.
|Initial:  7 = 111₂

Pass 1 (>> 0):  111 → 111  = 7
				↑↑↑
Pass 2 (>> 1):  111 → 011  = 3
				 ↑↑
Pass 3 (>> 2):  111 → 001  = 1
				  ↑
Pass 4 (>> 3):  111 → 000  = 0  ->>>>> stop
*/
static int	get_max_bits(t_node *stack)
{
	int	max_bits;
	int	size;

	size = stack_size(stack);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

/*

For each element in A: check if index >> bit has LSB = 0 or 1.
We sort by bit, if its 0 we send to B stack, if its 1 we send
to A stack bottom because it will be larger
((index >> bit) & 1) extracts the bit-th bit of index.

index	Binary	>> 0 & 1 (bit 0)	>> 1 & 1 (bit 1)
0	000	0	0
1	001	1	0
2	010	0	1
3	011	1	1
4	100	0	0
5	101	1	0
6	110	0	1
7	111	1	1

*/
static void	sort_by_bit(t_stack *s, t_bench *bench, int bit)
{
	int	size;
	int	i;

	size = s->size_a;
	i = 0;
	while (i < size)
	{
		if (((s->a->index >> bit) & 1) == 0)
			op_pb(s, bench);
		else
			ra(s, bench);
		i++;
	}
}

/*
we push everything back from b to a

*/
static void	push_all_back(t_stack *s, t_bench *bench)
{
	while (s->size_b > 0)
		op_pa(s, bench);
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_complex(t_stack *stack, t_bench *bench)
{
	int	max_bits;
	int	bit;

	if (stack->size_a <= 1 || is_sorted(stack->a))
		return ;
	ft_assign_index(stack->a, stack->size_a);
	bit = 0;
	max_bits = get_max_bits(stack->a);
	while (bit < max_bits)
	{
		sort_by_bit(stack, bench, bit);
		push_all_back(stack, bench);
		bit++;
	}
}
