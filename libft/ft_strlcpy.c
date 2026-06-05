/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:34 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 09:53:55 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The ft_strlcpy() function copies up to size - 1 characters
	from the NUL-terminated string src to dst, NUL-terminating
	the result.

	RETURN
	The ft_strlcpy() returns the total length of the string it
	tried to create. That means the length of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!src || !dst || !size)
		return (src_len);
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
	}
	*dst = 0;
	return (src_len);
}
