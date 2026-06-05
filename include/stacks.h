/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:25:55 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 14:31:24 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

/*
	Macros defined for easy code comprenhension
*/
# define SIMPLE_STRAT 	0x01
# define MEDIUM_STRAT 	0x02
# define COMPLEX_STRAT	0x04
# define ADAPT_STRAT	0x08
# define BENCH_MODE		0x10
# define ERROR_STRAT	0x80

/*
	Holds information representing the strategy chose to run on
	the stack.

	0000 0001 -> simple strat
	0000 0010 -> medium strat
	0000 0100 -> complex strat
	0000 1000 -> adaptative strat
	0001 0000 -> benchmark mode
	1000 0000 -> Error strat
*/
typedef unsigned char	t_flag;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node		*a;
	t_node		*b;

	int			size_a;
	int			size_b;
	int			total_ops;
	t_flag		strat;
}	t_stack;

typedef struct s_bench
{
	double	disorder_index;
	size_t	sa_ops;
	size_t	sb_ops;
	size_t	ss_ops;
	size_t	pa_ops;
	size_t	pb_ops;
	size_t	ra_ops;
	size_t	rb_ops;
	size_t	rr_ops;
	size_t	rra_ops;
	size_t	rrb_ops;
	size_t	rrr_ops;
}	t_bench;

#endif