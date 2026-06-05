/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:41:03 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 15:04:21 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_bench	bench;

	if (argc == 1)
		return (1);
	ft_init_stacks(&stack, argc - 1, &argv[1]);
	if (!stack.a)
		return (write(2, "Error\n", 6), 1);
	ft_init_bench(&bench, compute_disorder_index(stack.a));
	if (stack.strat & SIMPLE_STRAT)
		sort_simple(&stack, &bench);
	else if (stack.strat & MEDIUM_STRAT)
		sort_medium(&stack, &bench);
	else if (stack.strat & COMPLEX_STRAT)
		sort_complex(&stack, &bench);
	else if (stack.strat & ADAPT_STRAT)
		sort_adaptative(&stack, &bench);
	if (stack.strat & BENCH_MODE)
		ft_print_bench_mode(&stack, &bench);
	free_stack(&stack.a);
	free_stack(&stack.b);
	return (0);
}
