/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:53:59 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/08 15:02:40 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
function to make square root
and calculate most effective
window of the chunk
*/
int	ft_sqrt(int n)
{
	long	low;
	long	high;
	long	mid;
	long	sqr;

	if (n < 0)
		return (0);
	if (n <= 1)
		return (n);
	low = 0;
	high = n;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		sqr = mid * mid;
		if (sqr == n)
			return ((int)mid);
		if (sqr < n)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return ((int)high);
}

/*
when we use chunk aproach for a sort, we need to
have the dividing numbers assigned an index
depending on where they will be on the final
ordination, so here we just assign the index in
the struct of the stack node

*/
void	assign_indices(t_node *stack)
{
	int		index;
	t_node	*current;
	t_node	*comparison;

	current = stack;
	while (current)
	{
		index = 0;
		comparison = stack;
		while (comparison)
		{
			if (current->value > comparison->value)
				index++;
			comparison = comparison->next;
		}
		current->index = index;
		current = current->next;
	}
}

/*
to keep creating the chunk sort and
do the proper order, we need to find
where do we start, and we also need to
know where is the first number that we need
to put on the pile
*/
int	find_minimum_index_pos(t_node *stack)
{
	int		min_pos;
	int		min_index;
	int		pos;
	t_node	*current;

	current = stack;
	min_index = current -> index;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current -> index < min_index)
		{
			min_index = current -> index;
			min_pos = pos;
		}
		pos++;
		current = current -> next;
	}
	return (min_pos);
}

int	find_max_index_pos(t_node *stack)
{
	int		max_idx;
	int		max_pos;
	int		pos;
	t_node	*current;

	if (!stack)
		return (-1);
	max_idx = stack->index;
	max_pos = 0;
	pos = 0;
	current = stack;
	while (current)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

/*
we push chunks to the b piles, in case we cantt
push we rotate positions to semi order it
*/
void	push_chunk_to_b(t_stack *s, t_bench *bench, int min_idx, int max_idx)
{
	int	pushed;

	pushed = 0;
	while ((pushed < (max_idx - min_idx + 1)
			&& s->size_a > 0))
	{
		if (s->a->index >= min_idx && s->a->index <= max_idx)
		{
			op_pb(s, bench);
			pushed++;
		}
		else
			ra(s, bench);
	}
}
