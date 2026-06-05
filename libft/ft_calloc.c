/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:47:34 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:22:11 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The  calloc() function allocates memory for an array of nmemb elements of 
	size bytes each and returns a pointer to the allocated memory.  The memory
	is  set to  zero.  If nmemb or size is 0, then calloc() returns a unique 
	pointer value that can later be successfully passed to free().

	RETURN
	A pointer to the start of the memory allocated.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memptr;
	size_t	total_bytes;

	if (size != 0 && nmemb > 2147483647 / size)
		return (0);
	total_bytes = nmemb * size;
	memptr = malloc(total_bytes);
	if (!memptr)
		return (0);
	ft_bzero(memptr, total_bytes);
	return (memptr);
}
