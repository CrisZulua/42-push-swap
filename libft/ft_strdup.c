/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:50:20 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:40:02 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The  ft_strdup() function returns a pointer to a new string which is a 
	duplicate of the string s. Memory for the new string is obtained  with
	malloc(), and can be freed with free().

	RETURN
	On success, the ft_strdup() function returns a pointer to the duplicated
	string.
	It  returns NULL if insufficient memory was available.
*/
char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*scpy;

	slen = ft_strlen(s) + 1;
	scpy = (char *)malloc(slen * sizeof(char));
	if (!scpy)
		return (0);
	ft_memcpy(scpy, s, slen);
	return (scpy);
}
