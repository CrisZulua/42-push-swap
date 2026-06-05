/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:49 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:34:18 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The ft_strnstr() function locates the first occurrence of the null-termi-
	nated  string little in the string big, where not more than len charac-
	ters are searched.  Characters that appear after a `\0'	character  are
	not  searched.

	RETURN
	If little is an empty string, big is returned; if little occurs nowhere
	in big, NULL is returned; otherwise a pointer to the first character of
	the first occurrence of little is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	size_t	blen;
	size_t	i;
	size_t	j;

	llen = ft_strlen(little);
	blen = ft_strlen(big);
	if (!llen)
		return ((char *)big);
	if (llen > len || llen > blen)
		return (NULL);
	i = 0;
	while (i <= len - llen && big[i])
	{
		if (big[i] == little[0])
		{
			j = i;
			while (big[j] && little[j - i] && big[j] == little[j - i])
				j++;
			if (!little[j - i])
				return (((char *)big + i));
		}
		i++;
	}
	return (NULL);
}
