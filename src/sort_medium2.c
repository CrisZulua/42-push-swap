/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:51:48 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/08 10:36:52 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
we just push back the chunk and order it
*/
void	push_back_sorted(t_stack *s, t_bench *bench)
{
	int	max_pos;

	while (s->size_b > 0)
	{
		max_pos = find_max_index_pos(s->b);
		rotate_helper_to_top_b(s, bench, max_pos);
		op_pa(s, bench);
	}
}

/*
optimal chunk size according to theory
*/
static int	get_chunk_size(int size)
{
	int	res;

	res = ft_sqrt(size);
	if (res < 2)
		res = 2;
	return (res);
}

static int	get_max_idx(int min_idx, int chunk_size, int size)
{
	int	max_idx;

	max_idx = min_idx + chunk_size - 1;
	if (max_idx >= size)
		max_idx = size - 1;
	return (max_idx);
}

static void	push_all_chunks(t_stack *s, t_bench *b, int size, int chunk_size)
{
	int	chunks;
	int	min_idx;
	int	max_idx;
	int	i;

	chunks = (size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunks)
	{
		min_idx = i * chunk_size;
		max_idx = get_max_idx(min_idx, chunk_size, size);
		push_chunk_to_b(s, b, min_idx, max_idx);
		i++;
	}
}

/*
assigns the indexes, then it calculate chunk size
and pushes all chunk to the B pile.
Then it comes back and pushes back to A sorted
*/
void	sort_medium(t_stack *s, t_bench *bench)
{
	int	size;
	int	chunk_size;

	size = s->size_a;
	if (size <= 1 || is_sorted(s->a))
		return ;
	assign_indices(s->a);
	chunk_size = get_chunk_size(size);
	push_all_chunks(s, bench, size, chunk_size);
	push_back_sorted(s, bench);
}
