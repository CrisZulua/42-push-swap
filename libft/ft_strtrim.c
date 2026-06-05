/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:56 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 12:02:16 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrinset(const char *c, char const *set)
{
	while (*set)
	{
		if (*c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_trim_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	if (!end)
		return (0);
	start = 0;
	while (ft_chrinset(&s1[start], set) && start < end)
		start++;
	return (start);
}

static size_t	ft_trim_end(char const *s1, char const *set, size_t start)
{
	long	end_trim;
	long	end;
	long	lstart;

	lstart = (long)start;
	end = ft_strlen(s1);
	if (!end)
		return (0);
	end_trim = end - 1;
	while (ft_chrinset(&s1[end_trim], set) && end_trim >= lstart)
		end_trim--;
	return (end_trim + 1);
}

/*
	DESCRIPTION
	Allocates memory and returns a copy of 's1' with
	characters from 'set' removed from the beginning
	and the end.

	RETURN
	A pointer to the trim string.
	NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trim_str;

	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set, start);
	trim_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trim_str)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		trim_str[i] = s1[i + start];
		i++;
	}
	trim_str[i] = 0;
	return (trim_str);
}
