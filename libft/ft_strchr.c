/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:17 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 15:31:40 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The  ft_strchr() function search the first occurrence of the character
	c in the string s.

	Here "character" means "byte"; these function does not work with wide or
	multibyte characters.

	RETURN
	The ft_strchr() returns a pointer tot he matched character or NULL
	if the character is not found. The terminating null byte  is  considered
	part of the string, so that if c is specified as '\0', these functions
	return a pointer to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!uc)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	return (0);
}
