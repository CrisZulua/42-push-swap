/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:56:10 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 14:34:06 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_find_min_without_index(t_node *stack)
{
	t_node	*curr;
	t_node	*min;

	min = NULL;
	curr = stack;
	while (curr)
	{
		if (!(curr->index) && (!min || (curr->value < min->value)))
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	ft_assign_index(t_node *stack, int stack_size)
{
	t_node	*curr;
	int		i;

	i = 1;
	while (i <= stack_size)
	{
		curr = ft_find_min_without_index(stack);
		curr->index = i;
		i++;
	}
}
