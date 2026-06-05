/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:30:47 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 11:39:42 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	DESCRIPTION
	This function creates a new node given a token thats converted to a long
	variable. If the long value overflows an integer the node can not be
	created.

	RETURN
	A pointer if the node was created successfully
	NULL if the node could not be created
*/
static t_node	*ft_create_node(char *token)
{
	long	num;
	t_node	*node;

	if (ft_check_chars_in_token(token))
		return (NULL);
	num = ft_atol(token);
	if (num > INT_MAX || num < INT_MIN)
		return (NULL);
	node = new_node(num);
	if (!node)
		return (NULL);
	return (node);
}

/*
	DESCRIPTION
	This function adds a new node to the back of the stack.
*/
static void	ft_stack_add_back(t_node **stack, t_node *node)
{
	t_node	*curr;

	if (!node)
		return ;
	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}

/*
	DESCRIPTION
	This function creates a stack based on a list of numbers given
	as a unique string separated by spaces.

	RETURN
	A pointer to the head of the stack
	NULL if memory allocation fails
*/
t_node	*ft_create_stack_unique_arg(char *arg)
{
	size_t	i;
	t_node	*stack;
	t_node	*node;
	char	**tokens;

	i = 0;
	stack = NULL;
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (NULL);
	while (tokens[i])
	{
		node = ft_create_node(tokens[i]);
		if (!node)
		{
			ft_free_tokens(tokens);
			ft_free_stack(stack);
			return (NULL);
		}
		ft_stack_add_back(&stack, node);
		i++;
	}
	ft_free_tokens(tokens);
	return (stack);
}

/*
	DESRCRIPTION
	This function creates a stack given a series of tokens. The tokens
	given go between current_arg to argn - 1 indexes of args.

	RETURN
	A pointer to the stack created
	NULL if the stack could not be created
*/
t_node	*ft_create_stack_several_arg(int argn, char **args, int current_arg)
{
	t_node	*stack;
	t_node	*node;

	stack = NULL;
	while (current_arg < argn)
	{
		node = ft_create_node(args[current_arg]);
		if (!node)
		{
			ft_free_stack(stack);
			return (NULL);
		}
		ft_stack_add_back(&stack, node);
		current_arg++;
	}
	return (stack);
}
