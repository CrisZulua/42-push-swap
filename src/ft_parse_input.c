/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:16:40 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 15:02:24 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	DESCRIPTION
	This function checks for repeated numbers inside the stack

	RETURN
	1 if there is one repeated number
	0 otherwise
*/
static int	ft_check_repeated_nums(t_node *stack)
{
	t_node	*curr;
	t_node	*aux;

	curr = stack;
	while (curr)
	{
		aux = curr->next;
		while (aux)
		{
			if (curr->value == aux->value)
				return (1);
			aux = aux->next;
		}
		curr = curr->next;
	}
	return (0);
}

/*
	DESCRIPTION
	This function parse the input given.
	The parsing follows this structure:
		- Parse flags (simple, medium, complex, adaptative, bench)
		- Creates the stack from the numeric argument/s
		- Checks for repeated numbers in stack

	RETURN
	A pointer to the stack created.
	NULL in case of errors creating the stack
*/
t_node	*ft_parse_input(int argn, char **args, t_flag *strat_fl)
{
	size_t	current_arg;
	t_node	*stack;

	current_arg = ft_get_flags(argn, args, strat_fl);
	if ((*strat_fl & ERROR_STRAT) || (argn - current_arg == 0))
		return (NULL);
	if (argn - current_arg > 1)
		stack = ft_create_stack_several_arg(argn, args, current_arg);
	else
		stack = ft_create_stack_unique_arg(args[current_arg]);
	if (ft_check_repeated_nums(stack))
	{
		ft_free_stack(stack);
		return (NULL);
	}
	return (stack);
}
