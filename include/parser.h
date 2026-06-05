/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:53:28 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 15:01:20 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "stacks.h"
# include <limits.h>

int		ft_strcmp(const char *s1, const char *s2);

// ------------------ FLAG PARSER ---------------------------------------------

size_t	ft_get_flags(int argn, char **args, t_flag *strat_fl);

// ------------------ STACK PARSER UTILS --------------------------------------

int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *nptr);
void	ft_free_tokens(char **tokens);
void	ft_free_stack(t_node *stack);

// ------------------ STACK PARSER  -------------------------------------------

t_node	*ft_create_stack_unique_arg(char *arg);
t_node	*ft_create_stack_several_arg(int argn, char **args, int current_arg);
int		ft_check_chars_in_token(char *token);
t_node	*ft_parse_input(int argn, char **args, t_flag *strat_fl);

void	ft_init_stacks(t_stack *stack, int argn, char **args);

#endif