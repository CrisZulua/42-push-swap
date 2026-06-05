/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:00:22 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 15:03:18 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stack_size(t_node *stack)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	ft_init_stacks(t_stack *stack, int argn, char **args)
{
	stack->strat = 0;
	stack->a = ft_parse_input(argn, args, &stack->strat);
	stack->size_a = ft_stack_size(stack->a);
	stack->b = NULL;
	stack->size_b = 0;
	stack->total_ops = 0;
}
