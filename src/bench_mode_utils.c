/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:35:35 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 11:39:55 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_bench(t_bench *bench, double disorder_idx)
{
	bench->disorder_index = disorder_idx;
	bench->sa_ops = 0;
	bench->sb_ops = 0;
	bench->ss_ops = 0;
	bench->pa_ops = 0;
	bench->pb_ops = 0;
	bench->ra_ops = 0;
	bench->rb_ops = 0;
	bench->rr_ops = 0;
	bench->rra_ops = 0;
	bench->rrb_ops = 0;
	bench->rrr_ops = 0;
}
