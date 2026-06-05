/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:36:52 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 14:52:19 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	DESCRIPTION
	This funciton compares s1 and s2.

	RETURN
	0 if equal
	Negative value if s1 < s2
	Positive value if s1 > s2
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*
	DESCRIPTION
	The ft_atoi() function converts the initial portion of the string pointed
	to by nptr to long.

	RETURN VALUE
	The converted value or 0 on error.
*/
long	ft_atol(const char *nptr)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (sign * num);
}

/*
	DESCRIPTION
	This function frees the pointer array tokens, previously allocated.
	RETURN
*/
void	ft_free_tokens(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/*
	DESCRIPTION
	This function frees a stack.
*/
void	ft_free_stack(t_node *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

/*
	DESCRIPTION
	This function checks for an alphabetic character inside the string token.

	RETURN
	1 if any alphabetic char is found or there is no numbers inside the token
	0 otherwise
*/
int	ft_check_chars_in_token(char *token)
{
	size_t	i;
	int		digit_flag;

	i = 0;
	digit_flag = 0;
	while (token[i])
	{
		if (!ft_isdigit((unsigned char)token[i]))
		{
			if (token[i] != '-' && token[i] != '+')
				return (1);
		}
		else
			digit_flag = 1;
		i++;
	}
	if (!digit_flag)
		return (1);
	return (0);
}
