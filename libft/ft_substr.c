/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:51:06 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 15:54:49 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tlen(char const *s, unsigned int start, size_t len)
{
	size_t	ssize;

	ssize = ft_strlen(s);
	if (ssize > start)
	{
		if (len < ssize - start)
			return (len);
		else
			return (ssize - start);
	}
	return (0);
}

/*
	DESCRIPTION
	Allocates memory and returns a substring from the string s.
	The substring starts at index 'start' and has a maximum
	length of 'len'.

	RETURN
	A pointer to the substring.
	NULL if the allocation fails
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	total_len;

	if (!s)
		return (NULL);
	total_len = tlen(s, start, len);
	substr = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
