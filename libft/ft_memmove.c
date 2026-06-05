/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:49:28 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/27 10:33:34 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The  ft_memmove() function copies n bytes from memory area src to memory
	area dest.  The memory areas may overlap: copying takes place as though  the
	bytes  in  src  are  first copied  into a temporary array that does not
	overlap src or dest, and the bytes are then copied from the temporary array
	to dest.

	RETURN
	The ft_memmove() returns a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*psrc;
	unsigned char		*pdest;

	psrc = (const unsigned char *)src;
	pdest = (unsigned char *)dest;
	if (dest < src)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		psrc += n;
		pdest += n;
		while (n--)
			*--pdest = *--psrc;
	}
	return (dest);
}
