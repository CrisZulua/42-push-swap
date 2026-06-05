/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:51:09 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 12:31:28 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	If  c  is  an uppercase letter, tolower() returns its lowercase equiva‐
	lent, if c is neither an unsigned char value nor EOF, the behavior  of
	these function is undefined.

	RETURN
	Uppercase equivalent.
*/
int	ft_tolower(int c)
{
	if (c == -1)
		return (-1);
	if (!ft_isalpha(c) || c > 90)
		return ((unsigned char)c);
	return ((unsigned char)c + 32);
}
