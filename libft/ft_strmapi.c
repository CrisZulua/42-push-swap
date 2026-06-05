/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:41 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:34:01 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	Applies the function f to each character of the string s,
	passing it's index as the first argument and the character
	itself as the second. A new string is created to store the
	results from the successive applications of f.

	RETURN
	A pointer to the string created.
	NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*smap;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	smap = (char *)malloc((slen + 1) * sizeof(char));
	if (!smap)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		smap[i] = (*f)(i, s[i]);
		i++;
	}
	smap[slen] = 0;
	return (smap);
}
