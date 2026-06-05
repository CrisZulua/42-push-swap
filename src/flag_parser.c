/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:27:13 by czuluaga          #+#    #+#             */
/*   Updated: 2026/05/08 10:05:51 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	DESCRIPTION
	This function match an argument with its correponding bit flag on strat_fl.
	If there is repeated arguments or and unknown argument the bit ERROR_STRAT
	is set.

	If the argument is a known flag the corresponding bit is set.
*/
static void	ft_match_flag(char *arg, t_flag *strat_fl)
{
	if (!ft_strcmp(arg, "--simple") && !(*strat_fl & (~BENCH_MODE)))
		*strat_fl |= SIMPLE_STRAT;
	else if (!ft_strcmp(arg, "--medium") && !(*strat_fl & (~BENCH_MODE)))
		*strat_fl |= MEDIUM_STRAT;
	else if (!ft_strcmp(arg, "--complex") && !(*strat_fl & (~BENCH_MODE)))
		*strat_fl |= COMPLEX_STRAT;
	else if (!ft_strcmp(arg, "--adaptive") && !(*strat_fl & (~BENCH_MODE)))
		*strat_fl |= ADAPT_STRAT;
	else if (!ft_strcmp(arg, "--bench") && !(*strat_fl & BENCH_MODE))
		*strat_fl |= BENCH_MODE;
	else
		*strat_fl = ERROR_STRAT;
}

/*
	DESCRIPTION
	This function checks for flags set in the execution arguments
	This means:
		- simple strat selector
		- medium strat selector
		- complex strat selector
		- adaptative strat selector
		- benchmark mode selector

	If there is no arguments given the bit ADAPT_STRAT is set as it is
	the default behaviour.

	RETURN
	Returns the index where the arguments left are not flags inside the
	arguments array args.
*/
size_t	ft_get_flags(int argn, char **args, t_flag *strat_fl)
{
	int	i;

	i = 0;
	while (i < argn)
	{
		if (args[i][0] == '-' && args[i][1] == '-')
			ft_match_flag(args[i], strat_fl);
		else
			break ;
		i++;
	}
	if (!(*strat_fl & (~BENCH_MODE)))
		*strat_fl |= ADAPT_STRAT;
	return (i);
}
