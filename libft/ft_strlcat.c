/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:31 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 15:23:15 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The strlcat() function appends the NUL-terminated string
	src to the end of dst. It will append at most
	size - strlen(dst) - 1 bytes, NUL-terminating the result.

	RETURN
	The function ft_strlcat() returns the total length of the
	string it tried to create. That means the initial length
	of dst plus the length of src.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	slen = ft_strlen(src);
	dlen = ft_strlen((const char *)dst);
	if (!src || !dst || (size <= dlen))
		return (slen + size);
	else if (size > (dlen + slen))
		size = dlen + slen + 1;
	i = 0;
	while (i < (size - dlen - 1) && *src)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = 0;
	return (slen + dlen);
}
