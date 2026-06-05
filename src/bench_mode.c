/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:51:59 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/13 09:31:26 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_disorder(double disorder_index)
{
	int	integer;
	int	fraction;

	integer = (long)disorder_index;
	fraction = (disorder_index - integer) * 100;
	write(2, "[bench] disorder:  ", 18);
	ft_putnbr_fd(integer, 2);
	write(2, ".", 1);
	ft_putnbr_fd(fraction, 2);
	write(2, "%\n", 2);
}

static void	ft_print_strategy(t_flag strat_flag)
{
	if (strat_flag & ADAPT_STRAT)
	{
		if (strat_flag & SIMPLE_STRAT)
			write(2, "[bench] strategy: Adaptative / O(n)\n", 36);
		if (strat_flag & MEDIUM_STRAT)
			write(2, "[bench] strategy: Adaptative / O(n sqrt(n))\n", 44);
		if (strat_flag & COMPLEX_STRAT)
			write(2, "[bench] strategy: Adaptative / O(n log(n))\n", 43);
	}
	else if (strat_flag & SIMPLE_STRAT)
		write(2, "[bench] strategy: Simple / O(n)\n", 32);
	else if (strat_flag & MEDIUM_STRAT)
		write(2, "[bench] strategy: Medium / O(n sqrt(n)\n", 39);
	else if (strat_flag & COMPLEX_STRAT)
		write(2, "[bench] strategy: Complex / O(n log(n))\n", 40);
}

static void	ft_print_total_ops(int total_ops)
{
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(total_ops, 2);
	write(2, "\n", 1);
}

static void	ft_print_operations(t_bench *bench)
{
	write(2, "[bench] sa:  ", 13);
	ft_putnbr_fd(bench->sa_ops, 2);
	write(2, "  sb:  ", 7);
	ft_putnbr_fd(bench->sb_ops, 2);
	write(2, "  ss:  ", 7);
	ft_putnbr_fd(bench->ss_ops, 2);
	write(2, "  pa:  ", 7);
	ft_putnbr_fd(bench->pa_ops, 2);
	write(2, "  pb:  ", 7);
	ft_putnbr_fd(bench->pb_ops, 2);
	write(2, "\n", 1);
	write(2, "[bench] ra:  ", 13);
	ft_putnbr_fd(bench->ra_ops, 2);
	write(2, "  rb:  ", 7);
	ft_putnbr_fd(bench->rb_ops, 2);
	write(2, "  rr:  ", 7);
	ft_putnbr_fd(bench->rr_ops, 2);
	write(2, "  rra:  ", 8);
	ft_putnbr_fd(bench->rra_ops, 2);
	write(2, "  rrb:  ", 8);
	ft_putnbr_fd(bench->rrb_ops, 2);
	write(2, "  rrr:  ", 8);
	ft_putnbr_fd(bench->rrr_ops, 2);
	write(2, "\n", 1);
}

void	ft_print_bench_mode(t_stack *stack, t_bench *bench)
{
	ft_print_disorder(bench->disorder_index * 100);
	ft_print_strategy(stack->strat);
	ft_print_total_ops(stack->total_ops);
	ft_print_operations(bench);
}
