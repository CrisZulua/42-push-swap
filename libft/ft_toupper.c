/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:51:13 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 12:29:06 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION:
	If c is a lowercase letter, toupper() returns its uppercase equivalent.
	If c is neither an unsigned char value nor EOF, the behavior  of  these
	functions is undefined.

	RETURN
	Lowercase equivalent.
*/
int	ft_toupper(int c)
{
	if (c == -1)
		return (-1);
	if (!ft_isalpha(c) || c < 97)
		return ((unsigned char)c);
	return ((unsigned char)c - 32);
}
