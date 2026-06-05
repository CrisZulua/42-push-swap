/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:48:53 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:35:52 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The ft_memcmp() function compares the first n bytes (each interpreted as
	unsigned char) of the memory areas s1 and s2.

	RETURN
	The ft_memcmp() function returns an integer less  than,  equal  to,  or
	greater than zero if the first n bytes of s1 is found, respectively, to
	be less than, to match, or be greater than the first n bytes of s2.

	For  a  nonzero return value, the sign is determined by the sign of the
	difference between the first pair of  bytes  (interpreted  as  unsigned
	char) that differ in s1 and s2.

	If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
