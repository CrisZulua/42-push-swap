/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:51 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 15:33:06 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The ft_strrchr() search for the last occurrence of the character c in
	the string s.

	Here "character" means "byte"; these function does not work with wide or
	multibyte characters.

	RETURN
	The ft_strrchr() returns a pointer tot he matched character or NULL
	if the character is not found. The terminating null byte  is  considered
	part of the string, so that if c is specified as '\0', these functions
	return a pointer to the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	int				slen;
	unsigned char	uc;

	uc = (unsigned char)c;
	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (*(s + slen) == uc)
			return ((char *)(s + slen));
		slen--;
	}
	return (NULL);
}
